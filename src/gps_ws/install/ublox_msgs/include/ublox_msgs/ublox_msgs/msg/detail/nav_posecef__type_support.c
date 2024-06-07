// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ublox_msgs:msg/NavPOSECEF.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ublox_msgs/msg/detail/nav_posecef__rosidl_typesupport_introspection_c.h"
#include "ublox_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ublox_msgs/msg/detail/nav_posecef__functions.h"
#include "ublox_msgs/msg/detail/nav_posecef__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ublox_msgs__msg__NavPOSECEF__rosidl_typesupport_introspection_c__NavPOSECEF_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ublox_msgs__msg__NavPOSECEF__init(message_memory);
}

void ublox_msgs__msg__NavPOSECEF__rosidl_typesupport_introspection_c__NavPOSECEF_fini_function(void * message_memory)
{
  ublox_msgs__msg__NavPOSECEF__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ublox_msgs__msg__NavPOSECEF__rosidl_typesupport_introspection_c__NavPOSECEF_message_member_array[5] = {
  {
    "i_tow",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavPOSECEF, i_tow),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ecef_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavPOSECEF, ecef_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ecef_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavPOSECEF, ecef_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ecef_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavPOSECEF, ecef_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "p_acc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ublox_msgs__msg__NavPOSECEF, p_acc),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ublox_msgs__msg__NavPOSECEF__rosidl_typesupport_introspection_c__NavPOSECEF_message_members = {
  "ublox_msgs__msg",  // message namespace
  "NavPOSECEF",  // message name
  5,  // number of fields
  sizeof(ublox_msgs__msg__NavPOSECEF),
  ublox_msgs__msg__NavPOSECEF__rosidl_typesupport_introspection_c__NavPOSECEF_message_member_array,  // message members
  ublox_msgs__msg__NavPOSECEF__rosidl_typesupport_introspection_c__NavPOSECEF_init_function,  // function to initialize message memory (memory has to be allocated)
  ublox_msgs__msg__NavPOSECEF__rosidl_typesupport_introspection_c__NavPOSECEF_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ublox_msgs__msg__NavPOSECEF__rosidl_typesupport_introspection_c__NavPOSECEF_message_type_support_handle = {
  0,
  &ublox_msgs__msg__NavPOSECEF__rosidl_typesupport_introspection_c__NavPOSECEF_message_members,
  get_message_typesupport_handle_function,
  &ublox_msgs__msg__NavPOSECEF__get_type_hash,
  &ublox_msgs__msg__NavPOSECEF__get_type_description,
  &ublox_msgs__msg__NavPOSECEF__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ublox_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ublox_msgs, msg, NavPOSECEF)() {
  if (!ublox_msgs__msg__NavPOSECEF__rosidl_typesupport_introspection_c__NavPOSECEF_message_type_support_handle.typesupport_identifier) {
    ublox_msgs__msg__NavPOSECEF__rosidl_typesupport_introspection_c__NavPOSECEF_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ublox_msgs__msg__NavPOSECEF__rosidl_typesupport_introspection_c__NavPOSECEF_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
