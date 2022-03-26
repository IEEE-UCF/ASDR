// Generated by gencpp from file asdr/set_velocity.msg
// DO NOT EDIT!


#ifndef ASDR_MESSAGE_SET_VELOCITY_H
#define ASDR_MESSAGE_SET_VELOCITY_H

#include <ros/service_traits.h>


#include <asdr/set_velocityRequest.h>
#include <asdr/set_velocityResponse.h>


namespace asdr
{

struct set_velocity
{

typedef set_velocityRequest Request;
typedef set_velocityResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct set_velocity
} // namespace asdr


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::asdr::set_velocity > {
  static const char* value()
  {
    return "144a16e4d6b53a0dbadc2e617460a173";
  }

  static const char* value(const ::asdr::set_velocity&) { return value(); }
};

template<>
struct DataType< ::asdr::set_velocity > {
  static const char* value()
  {
    return "asdr/set_velocity";
  }

  static const char* value(const ::asdr::set_velocity&) { return value(); }
};


// service_traits::MD5Sum< ::asdr::set_velocityRequest> should match
// service_traits::MD5Sum< ::asdr::set_velocity >
template<>
struct MD5Sum< ::asdr::set_velocityRequest>
{
  static const char* value()
  {
    return MD5Sum< ::asdr::set_velocity >::value();
  }
  static const char* value(const ::asdr::set_velocityRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::asdr::set_velocityRequest> should match
// service_traits::DataType< ::asdr::set_velocity >
template<>
struct DataType< ::asdr::set_velocityRequest>
{
  static const char* value()
  {
    return DataType< ::asdr::set_velocity >::value();
  }
  static const char* value(const ::asdr::set_velocityRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::asdr::set_velocityResponse> should match
// service_traits::MD5Sum< ::asdr::set_velocity >
template<>
struct MD5Sum< ::asdr::set_velocityResponse>
{
  static const char* value()
  {
    return MD5Sum< ::asdr::set_velocity >::value();
  }
  static const char* value(const ::asdr::set_velocityResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::asdr::set_velocityResponse> should match
// service_traits::DataType< ::asdr::set_velocity >
template<>
struct DataType< ::asdr::set_velocityResponse>
{
  static const char* value()
  {
    return DataType< ::asdr::set_velocity >::value();
  }
  static const char* value(const ::asdr::set_velocityResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ASDR_MESSAGE_SET_VELOCITY_H
