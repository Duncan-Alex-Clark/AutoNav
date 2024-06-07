// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from data_interface:msg/Data.idl
// generated code does not contain a copyright notice

#ifndef DATA_INTERFACE__MSG__DETAIL__DATA__STRUCT_H_
#define DATA_INTERFACE__MSG__DETAIL__DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'gamepad'
#include "sensor_msgs/msg/detail/joy__struct.h"
// Member 'cam0'
// Member 'cam1'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in msg/Data in the package data_interface.
typedef struct data_interface__msg__Data
{
  sensor_msgs__msg__Joy gamepad;
  sensor_msgs__msg__Image cam0;
  sensor_msgs__msg__Image cam1;
  bool data_active;
  bool auto_active;
  float steering;
  float throttle;
} data_interface__msg__Data;

// Struct for a sequence of data_interface__msg__Data.
typedef struct data_interface__msg__Data__Sequence
{
  data_interface__msg__Data * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} data_interface__msg__Data__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DATA_INTERFACE__MSG__DETAIL__DATA__STRUCT_H_
