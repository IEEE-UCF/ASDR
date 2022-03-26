#pragma once

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h> 

#include <cstdint>
#include <memory>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include <numeric>

#include "ros/ros.h"
#include "ros/console.h"

class ROSLaunchManager 
{
	std::vector<pid_t> m_pids;

	std::atomic<bool> m_running;
	std::thread m_thread;
	std::mutex m_mutex;
	
public:
	ROSLaunchManager(ROSLaunchManager const &)
	{
	}

	ROSLaunchManager()
	{
		std::atomic_init(&m_running, true);

		m_thread = std::thread(&ROSLaunchManager::wait, this);
	}

	~ROSLaunchManager() 
	{
		if (m_running.load()) {
			m_running.store(false);

			if (m_thread.joinable()) {
				m_thread.join();
			}
		}
	}

	template<typename... Args>
	pid_t start(Args... args) 
	{
		std::vector<std::string> const args_vector = { args... };

		if (std::size(args_vector) > 0) {
			pid_t const pid = ::fork();

			if (pid == 0) {
				::setsid();
				
				::signal(SIGINT, SIG_IGN);
				
				::fclose(stdout);
				::fclose(stdin);
				::fclose(stderr);

				::execlp("roslaunch", "roslaunch", args..., nullptr);
			}
			else {
				std::scoped_lock<std::mutex> scoped_lock(m_mutex);

				std::string const args_string = std::accumulate(std::next(std::cbegin(args_vector)), std::cend(args_vector), args_vector[0], [](std::string const &lhs, std::string const &rhs) -> std::string { return lhs + " " + rhs; });

				ROS_INFO_STREAM("Starting \"roslaunch " << args_string.c_str() << "\" with PID " << pid << ".");

				m_pids.push_back(pid);
			}

			return pid;
		}
		else {
			throw std::runtime_error("ROSLaunchManager::start - No arguments provided.");
		}
	}

	void stop(pid_t const &pid, int32_t const &signal) 
	{
		std::scoped_lock<std::mutex> scoped_lock(m_mutex);

		std::vector<pid_t>::const_iterator pid_it = std::find(std::cbegin(m_pids), std::cend(m_pids), pid);

		if (pid_it != std::cend(m_pids)) {
			::kill(pid, signal);

			ROS_INFO_STREAM("Stopping process with PID " << pid << " and signal " << signal << ".");
		}
		else {
			throw std::runtime_error("ROSLaunchManager::stop - PID " + std::to_string(pid) + " not found.");
		}
	}

private:
	void wait()
	{
		while (m_running.load()) {
			std::scoped_lock<std::mutex> scoped_lock(m_mutex);

			for (std::vector<pid_t>::iterator pid_it = std::begin(m_pids); pid_it != std::end(m_pids); ++pid_it) {
				pid_t const pid = *pid_it;

				int32_t status;

				if (::waitpid(pid, &status, WUNTRACED | WCONTINUED | WNOHANG) == pid) {
					if (WIFEXITED(status)) {
						ROS_INFO_STREAM("PID " << pid << " exited with status " << WEXITSTATUS(status) << ".");

						pid_it = m_pids.erase(pid_it);

						if (pid_it == std::end(m_pids)) {
							break;
						}
					} 
					else if (WIFSIGNALED(status)) {
						ROS_INFO_STREAM("PID " << pid << " killed with signal " << WTERMSIG(status) << ".");

						pid_it = m_pids.erase(pid_it);

						if (pid_it == std::end(m_pids)) {
							break;
						}
					} 
					else if (WIFSTOPPED(status)) {
						ROS_INFO_STREAM("PID " << pid << " stopped with signal " << WSTOPSIG(status) << ".");
					} 
					else if (WIFCONTINUED(status)) {
						ROS_INFO_STREAM("PID " << pid << " continued.");
					}
				}
			}
		}

		std::scoped_lock<std::mutex> scoped_lock(m_mutex);

		for (pid_t const &pid : m_pids) {
			::kill(pid, SIGINT);

			int32_t status;

			::waitpid(pid, &status, 0);
		}
	}
};
