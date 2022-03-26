#pragma once

#include <stdexcept>
#include <memory>

#include "ros/ros.h"
#include "ros/console.h"

#include "asdr/set_state.h"
#include "asdr/get_state.h"
#include "asdr/set_velocity.h"

#include "cpprest/asyncrt_utils.h"
#include "cpprest/http_listener.h"
#include "cpprest/json.h"
#include "cpprest/uri.h"

class RESTNode
{
    ros::NodeHandle m_node_handle;
    
    web::http::experimental::listener::http_listener m_listener;

    ros::ServiceClient m_get_state_client;
    ros::ServiceClient m_set_state_client;
    ros::ServiceClient m_set_velocity_client;

public:
    RESTNode(ros::NodeHandle const &node_handle);
    ~RESTNode();

private:
    void onGet(web::http::http_request const &message);
    void onPost(web::http::http_request const &message);
};
