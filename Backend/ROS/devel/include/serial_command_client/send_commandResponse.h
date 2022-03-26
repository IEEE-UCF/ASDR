// Generated by gencpp from file serial_command_client/send_commandResponse.msg
// DO NOT EDIT!


#ifndef SERIAL_COMMAND_CLIENT_MESSAGE_SEND_COMMANDRESPONSE_H
#define SERIAL_COMMAND_CLIENT_MESSAGE_SEND_COMMANDRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace serial_command_client
{
template <class ContainerAllocator>
struct send_commandResponse_
{
  typedef send_commandResponse_<ContainerAllocator> Type;

  send_commandResponse_()
    : status(0)
    , buffer()  {
    }
  send_commandResponse_(const ContainerAllocator& _alloc)
    : status(0)
    , buffer(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _status_type;
  _status_type status;

   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _buffer_type;
  _buffer_type buffer;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(FAILURE)
  #undef FAILURE
#endif
#if defined(_WIN32) && defined(SUCCESS)
  #undef SUCCESS
#endif

  enum {
    FAILURE = 0u,
    SUCCESS = 1u,
  };


  typedef boost::shared_ptr< ::serial_command_client::send_commandResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::serial_command_client::send_commandResponse_<ContainerAllocator> const> ConstPtr;

}; // struct send_commandResponse_

typedef ::serial_command_client::send_commandResponse_<std::allocator<void> > send_commandResponse;

typedef boost::shared_ptr< ::serial_command_client::send_commandResponse > send_commandResponsePtr;
typedef boost::shared_ptr< ::serial_command_client::send_commandResponse const> send_commandResponseConstPtr;

// constants requiring out of line definition

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::serial_command_client::send_commandResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::serial_command_client::send_commandResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::serial_command_client::send_commandResponse_<ContainerAllocator1> & lhs, const ::serial_command_client::send_commandResponse_<ContainerAllocator2> & rhs)
{
  return lhs.status == rhs.status &&
    lhs.buffer == rhs.buffer;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::serial_command_client::send_commandResponse_<ContainerAllocator1> & lhs, const ::serial_command_client::send_commandResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace serial_command_client

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::serial_command_client::send_commandResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::serial_command_client::send_commandResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::serial_command_client::send_commandResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::serial_command_client::send_commandResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::serial_command_client::send_commandResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::serial_command_client::send_commandResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::serial_command_client::send_commandResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5be87bb0facce063fba275504571455a";
  }

  static const char* value(const ::serial_command_client::send_commandResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5be87bb0facce063ULL;
  static const uint64_t static_value2 = 0xfba275504571455aULL;
};

template<class ContainerAllocator>
struct DataType< ::serial_command_client::send_commandResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "serial_command_client/send_commandResponse";
  }

  static const char* value(const ::serial_command_client::send_commandResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::serial_command_client::send_commandResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 FAILURE=0\n"
"uint8 SUCCESS=1\n"
"uint8 status\n"
"uint8[] buffer\n"
;
  }

  static const char* value(const ::serial_command_client::send_commandResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::serial_command_client::send_commandResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.status);
      stream.next(m.buffer);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct send_commandResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::serial_command_client::send_commandResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::serial_command_client::send_commandResponse_<ContainerAllocator>& v)
  {
    s << indent << "status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.status);
    s << indent << "buffer[]" << std::endl;
    for (size_t i = 0; i < v.buffer.size(); ++i)
    {
      s << indent << "  buffer[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.buffer[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SERIAL_COMMAND_CLIENT_MESSAGE_SEND_COMMANDRESPONSE_H
