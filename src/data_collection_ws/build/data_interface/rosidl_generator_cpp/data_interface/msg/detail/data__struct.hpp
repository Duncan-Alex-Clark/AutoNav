// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from data_interface:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef DATA_INTERFACE__MSG__DETAIL__DATA__STRUCT_HPP_
#define DATA_INTERFACE__MSG__DETAIL__DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'gamepad'
#include "sensor_msgs/msg/detail/joy__struct.hpp"
// Member 'cam0'
// Member 'cam1'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__data_interface__msg__Data __attribute__((deprecated))
#else
# define DEPRECATED__data_interface__msg__Data __declspec(deprecated)
#endif

namespace data_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Data_
{
  using Type = Data_<ContainerAllocator>;

  explicit Data_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : gamepad(_init),
    cam0(_init),
    cam1(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data_active = false;
      this->auto_active = false;
      this->steering = 0.0f;
      this->throttle = 0.0f;
      this->latitude = 0.0f;
      this->longitude = 0.0f;
    }
  }

  explicit Data_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : gamepad(_alloc, _init),
    cam0(_alloc, _init),
    cam1(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data_active = false;
      this->auto_active = false;
      this->steering = 0.0f;
      this->throttle = 0.0f;
      this->latitude = 0.0f;
      this->longitude = 0.0f;
    }
  }

  // field types and members
  using _gamepad_type =
    sensor_msgs::msg::Joy_<ContainerAllocator>;
  _gamepad_type gamepad;
  using _cam0_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _cam0_type cam0;
  using _cam1_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _cam1_type cam1;
  using _data_active_type =
    bool;
  _data_active_type data_active;
  using _auto_active_type =
    bool;
  _auto_active_type auto_active;
  using _steering_type =
    float;
  _steering_type steering;
  using _throttle_type =
    float;
  _throttle_type throttle;
  using _latitude_type =
    float;
  _latitude_type latitude;
  using _longitude_type =
    float;
  _longitude_type longitude;

  // setters for named parameter idiom
  Type & set__gamepad(
    const sensor_msgs::msg::Joy_<ContainerAllocator> & _arg)
  {
    this->gamepad = _arg;
    return *this;
  }
  Type & set__cam0(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->cam0 = _arg;
    return *this;
  }
  Type & set__cam1(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->cam1 = _arg;
    return *this;
  }
  Type & set__data_active(
    const bool & _arg)
  {
    this->data_active = _arg;
    return *this;
  }
  Type & set__auto_active(
    const bool & _arg)
  {
    this->auto_active = _arg;
    return *this;
  }
  Type & set__steering(
    const float & _arg)
  {
    this->steering = _arg;
    return *this;
  }
  Type & set__throttle(
    const float & _arg)
  {
    this->throttle = _arg;
    return *this;
  }
  Type & set__latitude(
    const float & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const float & _arg)
  {
    this->longitude = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    data_interface::msg::Data_<ContainerAllocator> *;
  using ConstRawPtr =
    const data_interface::msg::Data_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<data_interface::msg::Data_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<data_interface::msg::Data_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      data_interface::msg::Data_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<data_interface::msg::Data_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      data_interface::msg::Data_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<data_interface::msg::Data_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<data_interface::msg::Data_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<data_interface::msg::Data_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__data_interface__msg__Data
    std::shared_ptr<data_interface::msg::Data_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__data_interface__msg__Data
    std::shared_ptr<data_interface::msg::Data_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Data_ & other) const
  {
    if (this->gamepad != other.gamepad) {
      return false;
    }
    if (this->cam0 != other.cam0) {
      return false;
    }
    if (this->cam1 != other.cam1) {
      return false;
    }
    if (this->data_active != other.data_active) {
      return false;
    }
    if (this->auto_active != other.auto_active) {
      return false;
    }
    if (this->steering != other.steering) {
      return false;
    }
    if (this->throttle != other.throttle) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    return true;
  }
  bool operator!=(const Data_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Data_

// alias to use template instance with default allocator
using Data =
  data_interface::msg::Data_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace data_interface

#endif  // DATA_INTERFACE__MSG__DETAIL__DATA__STRUCT_HPP_
