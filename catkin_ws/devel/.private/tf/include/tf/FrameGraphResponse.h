// Generated by gencpp from file tf/FrameGraphResponse.msg
// DO NOT EDIT!


#ifndef TF_MESSAGE_FRAMEGRAPHRESPONSE_H
#define TF_MESSAGE_FRAMEGRAPHRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace tf
{
template <class ContainerAllocator>
struct FrameGraphResponse_
{
  typedef FrameGraphResponse_<ContainerAllocator> Type;

  FrameGraphResponse_()
    : dot_graph()  {
    }
  FrameGraphResponse_(const ContainerAllocator& _alloc)
    : dot_graph(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _dot_graph_type;
  _dot_graph_type dot_graph;





  typedef boost::shared_ptr< ::tf::FrameGraphResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::tf::FrameGraphResponse_<ContainerAllocator> const> ConstPtr;

}; // struct FrameGraphResponse_

typedef ::tf::FrameGraphResponse_<std::allocator<void> > FrameGraphResponse;

typedef boost::shared_ptr< ::tf::FrameGraphResponse > FrameGraphResponsePtr;
typedef boost::shared_ptr< ::tf::FrameGraphResponse const> FrameGraphResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::tf::FrameGraphResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::tf::FrameGraphResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace tf

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsMessage': True, 'HasHeader': False, 'IsFixedSize': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'tf': ['/local-scratch/xlv/reward_shaping_ttr/catkin_ws/src/geometry/tf/msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsMessage< ::tf::FrameGraphResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::tf::FrameGraphResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tf::FrameGraphResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tf::FrameGraphResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::tf::FrameGraphResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::tf::FrameGraphResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::tf::FrameGraphResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c4af9ac907e58e906eb0b6e3c58478c0";
  }

  static const char* value(const ::tf::FrameGraphResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc4af9ac907e58e90ULL;
  static const uint64_t static_value2 = 0x6eb0b6e3c58478c0ULL;
};

template<class ContainerAllocator>
struct DataType< ::tf::FrameGraphResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "tf/FrameGraphResponse";
  }

  static const char* value(const ::tf::FrameGraphResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::tf::FrameGraphResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string dot_graph\n\
\n\
";
  }

  static const char* value(const ::tf::FrameGraphResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::tf::FrameGraphResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.dot_graph);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct FrameGraphResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::tf::FrameGraphResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::tf::FrameGraphResponse_<ContainerAllocator>& v)
  {
    s << indent << "dot_graph: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.dot_graph);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TF_MESSAGE_FRAMEGRAPHRESPONSE_H
