#include "rest_node.hpp"

RESTNode::RESTNode(ros::NodeHandle const &node_handle) : 
    m_node_handle { node_handle }, 
    m_listener { "http://0.0.0.0:8080" }
{   
    m_get_state_client = m_node_handle.serviceClient<asdr::get_state>(ros::names::resolve("get_state"));
    m_set_state_client = m_node_handle.serviceClient<asdr::set_state>(ros::names::resolve("set_state"));
    m_set_velocity_client = m_node_handle.serviceClient<asdr::set_velocity>(ros::names::resolve("set_velocity"));

    m_listener.support(web::http::methods::GET, std::bind(&RESTNode::onGet, this, std::placeholders::_1));
    m_listener.support(web::http::methods::POST, std::bind(&RESTNode::onPost, this, std::placeholders::_1));

    m_listener.open().wait();
}

RESTNode::~RESTNode()
{
    m_listener.close().wait();
}

void RESTNode::onGet(web::http::http_request const &request)
{
    std::vector<utility::string_t> const paths = web::uri::split_path(web::uri::decode(request.relative_uri().path()));

    if (paths[0] == "get_state") {
        asdr::get_state get_state_srv;

        if (m_get_state_client.call(get_state_srv)) {
            web::http::http_response response(web::http::status_codes::OK);

            response.headers().add("Content-Type", "text/plain; charset=UTF-8");
            response.headers().add("Access-Control-Allow-Origin", "*");
            
            response.set_body(get_state_srv.response.state);

            request.reply(response);

        }
        else {
            web::http::http_response response(web::http::status_codes::InternalError);

            response.headers().add("Content-Type", "text/plain; charset=UTF-8");
            response.headers().add("Access-Control-Allow-Origin", "*");
            
            request.reply(response);
        }
    }
    else {
        web::http::http_response response(web::http::status_codes::BadRequest);

        response.headers().add("Content-Type", "text/plain; charset=UTF-8");
        response.headers().add("Access-Control-Allow-Origin", "*");
        
        request.reply(response);
    }
}

void RESTNode::onPost(web::http::http_request const &request)
{
    std::vector<utility::string_t> const paths = web::uri::split_path(web::uri::decode(request.relative_uri().path()));

    std::map<utility::string_t, utility::string_t> const query = web::uri::split_query(web::uri::decode(request.request_uri().query()));

    if (paths[0] == "set_state") {
        asdr::set_state set_state_srv;

        try {
            set_state_srv.request.state = query.at("state");

            if (m_set_state_client.call(set_state_srv)) {
                web::http::http_response response(web::http::status_codes::OK);

                response.headers().add("Content-Type", "text/plain; charset=UTF-8");
                response.headers().add("Access-Control-Allow-Origin", "*");
                
                request.reply(response);
            }
            else {
                web::http::http_response response(web::http::status_codes::BadRequest);

                response.headers().add("Content-Type", "text/plain; charset=UTF-8");
                response.headers().add("Access-Control-Allow-Origin", "*");
                
                request.reply(response);
            }
        }
        catch (std::exception const &exception) {
            web::http::http_response response(web::http::status_codes::BadRequest);

            response.headers().add("Content-Type", "text/plain; charset=UTF-8");
            response.headers().add("Access-Control-Allow-Origin", "*");
            
            request.reply(response);
        }
    }
    else if (paths[0] == "set_velocity") {
        asdr::set_velocity set_velocity_srv;

        try {
            set_velocity_srv.request.linear = std::stod(query.at("linear"));
            set_velocity_srv.request.angular = std::stod(query.at("angular"));

            if (m_set_velocity_client.call(set_velocity_srv)) {
                web::http::http_response response(web::http::status_codes::OK);

                response.headers().add("Content-Type", "text/plain; charset=UTF-8");
                response.headers().add("Access-Control-Allow-Origin", "*");
                
                request.reply(response);
            }
            else {
                web::http::http_response response(web::http::status_codes::BadRequest);

                response.headers().add("Content-Type", "text/plain; charset=UTF-8");
                response.headers().add("Access-Control-Allow-Origin", "*");
                
                request.reply(response);
            }
        }
        catch (std::exception const &exception) {
            web::http::http_response response(web::http::status_codes::BadRequest);

            response.headers().add("Content-Type", "text/plain; charset=UTF-8");
            response.headers().add("Access-Control-Allow-Origin", "*");
            
            request.reply(response);
        }
    }
    else {
        web::http::http_response response(web::http::status_codes::BadRequest);

        response.headers().add("Content-Type", "text/plain; charset=UTF-8");
        response.headers().add("Access-Control-Allow-Origin", "*");
        
        request.reply(response);
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rest");

    ros::NodeHandle node_handle("~");
    
    try {
        RESTNode rest_node(node_handle);
        
        while (ros::ok()) {
            ros::spinOnce();
        }

        return 0;
    }
    catch (std::exception const &exception) {
        ROS_ERROR_STREAM(exception.what());

        return 1;
    }
}
