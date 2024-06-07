// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ublox_msgs:msg/MonGNSS.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ublox_msgs/msg/detail/mon_gnss__rosidl_typesupport_introspection_c.h"
#include "ublox_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ublox_msgs/msg/detail/mon_gnss__functions.h"
#include "ublox_msgs/msg/detail/mon_gnss__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__MonGNSS_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ublox_msgs__msg__MonGNSS__init(message_memory);
}

void ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__MonGNSS_fini_function(void * message_memory)
{
  ublox_msgs__msg__MonGNSS__fini(message_memory);
}

size_t ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__size_function__MonGNSS__reserved1(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__get_const_function__MonGNSS__reserved1(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__get_function__MonGNSS__reserved1(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__fetch_function__MonGNSS__reserved1(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__get_const_function__MonGNSS__reserved1(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__assign_function__MonGNSS__reserved1(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__get_function__MonGNSS__reserved1(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__MonGNSS_message_member_array[6] = {
  {
    "version",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__MonGNSS, version),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "supported",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__MonGNSS, supported),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "default_gnss",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__MonGNSS, default_gnss),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "enabled",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__MonGNSS, enabled),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "simultaneous",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__MonGNSS, simultaneous),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "reserved1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__MonGNSS, reserved1),  // bytes offset in struct
    NULL,  // default value
    ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__size_function__MonGNSS__reserved1,  // size() function pointer
    ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__get_const_function__MonGNSS__reserved1,  // get_const(index) function pointer
    ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__get_function__MonGNSS__reserved1,  // get(index) function pointer
    ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__fetch_function__MonGNSS__reserved1,  // fetch(index, &value) function pointer
    ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__assign_function__MonGNSS__reserved1,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__MonGNSS_message_members = {
  "ublox_msgs__msg",  // message namespace
  "MonGNSS",  // message name
  6,  // number of fields
  sizeof(ublox_msgs__msg__MonGNSS),
  ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__MonGNSS_message_member_array,  // message members
  ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__MonGNSS_init_function,  // function to initialize message memory (memory has to be allocated)
  ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__MonGNSS_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__MonGNSS_message_type_support_handle = {
  0,
  &ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__MonGNSS_message_members,
  get_message_typesupport_handle_function,
  &ublox_msgs__msg__MonGNSS__get_type_hash,
  &ublox_msgs__msg__MonGNSS__get_type_description,
  &ublox_msgs__msg__MonGNSS__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, MonGNSS)() {
  if (!ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__MonGNSS_message_type_support_handle.typesupport_identifier) {
    ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__MonGNSS_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ublox_msgs__msg__MonGNSS__rosidl_typesupport_introspection_c__MonGNSS_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
