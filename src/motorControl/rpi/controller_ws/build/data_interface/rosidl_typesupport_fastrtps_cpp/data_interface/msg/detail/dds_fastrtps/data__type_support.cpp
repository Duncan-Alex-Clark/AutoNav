// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from data_interface:msg/Data.idl
// generated code does not contain a copyright notice
#include "data_interface/msg/detail/data__rosidl_typesupport_fastrtps_cpp.hpp"
#include "data_interface/msg/detail/data__functions.h"
#include "data_interface/msg/detail/data__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace sensor_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const sensor_msgs::msg::Joy &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  sensor_msgs::msg::Joy &);
size_t get_serialized_size(
  const sensor_msgs::msg::Joy &,
  size_t current_alignment);
size_t
max_serialized_size_Joy(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace sensor_msgs

namespace sensor_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const sensor_msgs::msg::Image &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  sensor_msgs::msg::Image &);
size_t get_serialized_size(
  const sensor_msgs::msg::Image &,
  size_t current_alignment);
size_t
max_serialized_size_Image(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace sensor_msgs

// functions for sensor_msgs::msg::Image already declared above


namespace data_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_data_interface
cdr_serialize(
  const data_interface::msg::Data & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: gamepad
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.gamepad,
    cdr);
  // Member: cam0
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.cam0,
    cdr);
  // Member: cam1
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.cam1,
    cdr);
  // Member: data_active
  cdr << (ros_message.data_active ? true : false);
  // Member: auto_active
  cdr << (ros_message.auto_active ? true : false);
  // Member: steering
  cdr << ros_message.steering;
  // Member: throttle
  cdr << ros_message.throttle;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_data_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  data_interface::msg::Data & ros_message)
{
  // Member: gamepad
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.gamepad);

  // Member: cam0
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.cam0);

  // Member: cam1
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.cam1);

  // Member: data_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.data_active = tmp ? true : false;
  }

  // Member: auto_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.auto_active = tmp ? true : false;
  }

  // Member: steering
  cdr >> ros_message.steering;

  // Member: throttle
  cdr >> ros_message.throttle;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_data_interface
get_serialized_size(
  const data_interface::msg::Data & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: gamepad

  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.gamepad, current_alignment);
  // Member: cam0

  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.cam0, current_alignment);
  // Member: cam1

  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.cam1, current_alignment);
  // Member: data_active
  {
    size_t item_size = sizeof(ros_message.data_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: auto_active
  {
    size_t item_size = sizeof(ros_message.auto_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: steering
  {
    size_t item_size = sizeof(ros_message.steering);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: throttle
  {
    size_t item_size = sizeof(ros_message.throttle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_data_interface
max_serialized_size_Data(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: gamepad
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        sensor_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Joy(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: cam0
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        sensor_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Image(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: cam1
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        sensor_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Image(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: data_active
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: auto_active
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: steering
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: throttle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = data_interface::msg::Data;
    is_plain =
      (
      offsetof(DataType, throttle) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Data__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const data_interface::msg::Data *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Data__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<data_interface::msg::Data *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Data__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const data_interface::msg::Data *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Data__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Data(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Data__callbacks = {
  "data_interface::msg",
  "Data",
  _Data__cdr_serialize,
  _Data__cdr_deserialize,
  _Data__get_serialized_size,
  _Data__max_serialized_size
};

static rosidl_message_type_support_t _Data__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Data__callbacks,
  get_message_typesupport_handle_function,
  &data_interface__msg__Data__get_type_hash,
  &data_interface__msg__Data__get_type_description,
  &data_interface__msg__Data__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace data_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_data_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<data_interface::msg::Data>()
{
  return &data_interface::msg::typesupport_fastrtps_cpp::_Data__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, data_interface, msg, Data)() {
  return &data_interface::msg::typesupport_fastrtps_cpp::_Data__handle;
}

#ifdef __cplusplus
}
#endif
