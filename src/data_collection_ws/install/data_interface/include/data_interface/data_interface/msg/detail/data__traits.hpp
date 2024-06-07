// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from data_interface:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef DATA_INTERFACE__MSG__DETAIL__DATA__TRAITS_HPP_
#define DATA_INTERFACE__MSG__DETAIL__DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "data_interface/msg/detail/data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'gamepad'
#include "sensor_msgs/msg/detail/joy__traits.hpp"
// Member 'cam0'
// Member 'cam1'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace data_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Data & msg,
  std::ostream & out)
{
  out << "{";
  // member: gamepad
  {
    out << "gamepad: ";
    to_flow_style_yaml(msg.gamepad, out);
    out << ", ";
  }

  // member: cam0
  {
    out << "cam0: ";
    to_flow_style_yaml(msg.cam0, out);
    out << ", ";
  }

  // member: cam1
  {
    out << "cam1: ";
    to_flow_style_yaml(msg.cam1, out);
    out << ", ";
  }

  // member: data_active
  {
    out << "data_active: ";
    rosidl_generator_traits::value_to_yaml(msg.data_active, out);
    out << ", ";
  }

  // member: auto_active
  {
    out << "auto_active: ";
    rosidl_generator_traits::value_to_yaml(msg.auto_active, out);
    out << ", ";
  }

  // member: steering
  {
    out << "steering: ";
    rosidl_generator_traits::value_to_yaml(msg.steering, out);
    out << ", ";
  }

  // member: throttle
  {
    out << "throttle: ";
    rosidl_generator_traits::value_to_yaml(msg.throttle, out);
    out << ", ";
  }

  // member: latitude
  {
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << ", ";
  }

  // member: longitude
  {
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Data & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: gamepad
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gamepad:\n";
    to_block_style_yaml(msg.gamepad, out, indentation + 2);
  }

  // member: cam0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cam0:\n";
    to_block_style_yaml(msg.cam0, out, indentation + 2);
  }

  // member: cam1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cam1:\n";
    to_block_style_yaml(msg.cam1, out, indentation + 2);
  }

  // member: data_active
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_active: ";
    rosidl_generator_traits::value_to_yaml(msg.data_active, out);
    out << "\n";
  }

  // member: auto_active
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "auto_active: ";
    rosidl_generator_traits::value_to_yaml(msg.auto_active, out);
    out << "\n";
  }

  // member: steering
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steering: ";
    rosidl_generator_traits::value_to_yaml(msg.steering, out);
    out << "\n";
  }

  // member: throttle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "throttle: ";
    rosidl_generator_traits::value_to_yaml(msg.throttle, out);
    out << "\n";
  }

  // member: latitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << "\n";
  }

  // member: longitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Data & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace data_interface

namespace rosidl_generator_traits
{

[[deprecated("use data_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const data_interface::msg::Data & msg,
  std::ostream & out, size_t indentation = 0)
{
  data_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use data_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const data_interface::msg::Data & msg)
{
  return data_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<data_interface::msg::Data>()
{
  return "data_interface::msg::Data";
}

template<>
inline const char * name<data_interface::msg::Data>()
{
  return "data_interface/msg/Data";
}

template<>
struct has_fixed_size<data_interface::msg::Data>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value && has_fixed_size<sensor_msgs::msg::Joy>::value> {};

template<>
struct has_bounded_size<data_interface::msg::Data>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value && has_bounded_size<sensor_msgs::msg::Joy>::value> {};

template<>
struct is_message<data_interface::msg::Data>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DATA_INTERFACE__MSG__DETAIL__DATA__TRAITS_HPP_
