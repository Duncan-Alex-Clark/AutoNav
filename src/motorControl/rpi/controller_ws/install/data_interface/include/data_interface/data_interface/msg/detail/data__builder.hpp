// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from data_interface:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef DATA_INTERFACE__MSG__DETAIL__DATA__BUILDER_HPP_
#define DATA_INTERFACE__MSG__DETAIL__DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "data_interface/msg/detail/data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace data_interface
{

namespace msg
{

namespace builder
{

class Init_Data_throttle
{
public:
  explicit Init_Data_throttle(::data_interface::msg::Data & msg)
  : msg_(msg)
  {}
  ::data_interface::msg::Data throttle(::data_interface::msg::Data::_throttle_type arg)
  {
    msg_.throttle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::data_interface::msg::Data msg_;
};

class Init_Data_steering
{
public:
  explicit Init_Data_steering(::data_interface::msg::Data & msg)
  : msg_(msg)
  {}
  Init_Data_throttle steering(::data_interface::msg::Data::_steering_type arg)
  {
    msg_.steering = std::move(arg);
    return Init_Data_throttle(msg_);
  }

private:
  ::data_interface::msg::Data msg_;
};

class Init_Data_auto_active
{
public:
  explicit Init_Data_auto_active(::data_interface::msg::Data & msg)
  : msg_(msg)
  {}
  Init_Data_steering auto_active(::data_interface::msg::Data::_auto_active_type arg)
  {
    msg_.auto_active = std::move(arg);
    return Init_Data_steering(msg_);
  }

private:
  ::data_interface::msg::Data msg_;
};

class Init_Data_data_active
{
public:
  explicit Init_Data_data_active(::data_interface::msg::Data & msg)
  : msg_(msg)
  {}
  Init_Data_auto_active data_active(::data_interface::msg::Data::_data_active_type arg)
  {
    msg_.data_active = std::move(arg);
    return Init_Data_auto_active(msg_);
  }

private:
  ::data_interface::msg::Data msg_;
};

class Init_Data_cam1
{
public:
  explicit Init_Data_cam1(::data_interface::msg::Data & msg)
  : msg_(msg)
  {}
  Init_Data_data_active cam1(::data_interface::msg::Data::_cam1_type arg)
  {
    msg_.cam1 = std::move(arg);
    return Init_Data_data_active(msg_);
  }

private:
  ::data_interface::msg::Data msg_;
};

class Init_Data_cam0
{
public:
  explicit Init_Data_cam0(::data_interface::msg::Data & msg)
  : msg_(msg)
  {}
  Init_Data_cam1 cam0(::data_interface::msg::Data::_cam0_type arg)
  {
    msg_.cam0 = std::move(arg);
    return Init_Data_cam1(msg_);
  }

private:
  ::data_interface::msg::Data msg_;
};

class Init_Data_gamepad
{
public:
  Init_Data_gamepad()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Data_cam0 gamepad(::data_interface::msg::Data::_gamepad_type arg)
  {
    msg_.gamepad = std::move(arg);
    return Init_Data_cam0(msg_);
  }

private:
  ::data_interface::msg::Data msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::data_interface::msg::Data>()
{
  return data_interface::msg::builder::Init_Data_gamepad();
}

}  // namespace data_interface

#endif  // DATA_INTERFACE__MSG__DETAIL__DATA__BUILDER_HPP_
