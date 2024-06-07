// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ublox_msgs:msg/CfgRATE.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_RATE__STRUCT_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_RATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'CLASS_ID'.
enum
{
  ublox_msgs__msg__CfgRATE__CLASS_ID = 6
};

/// Constant 'MESSAGE_ID'.
enum
{
  ublox_msgs__msg__CfgRATE__MESSAGE_ID = 8
};

/// Constant 'TIME_REF_UTC'.
enum
{
  ublox_msgs__msg__CfgRATE__TIME_REF_UTC = 0
};

/// Constant 'TIME_REF_GPS'.
enum
{
  ublox_msgs__msg__CfgRATE__TIME_REF_GPS = 1
};

/// Constant 'TIME_REF_GLONASS'.
/**
  * not supported in protocol versions less than 18
 */
enum
{
  ublox_msgs__msg__CfgRATE__TIME_REF_GLONASS = 2
};

/// Constant 'TIME_REF_BEIDOU'.
/**
  * not supported in protocol versions less than 18
 */
enum
{
  ublox_msgs__msg__CfgRATE__TIME_REF_BEIDOU = 3
};

/// Constant 'TIME_REF_GALILEO'.
/**
  * not supported in protocol versions less than 18
 */
enum
{
  ublox_msgs__msg__CfgRATE__TIME_REF_GALILEO = 4
};

/// Struct defined in msg/CfgRATE in the package ublox_msgs.
/**
  * CFG-RATE (0x06 0x08)
  * Navigation/Measurement Rate Settings
  *
  * This message allows the user to alter the rate at which navigation solutions
  * (and the measurements that they depend on) are generated by the receiver. The
  * calculation of the navigation solution will always be aligned to the top of a
  * second zero (first second of the week) of the configured reference time
  * system. For protocol version 18 and later the navigation period is an integer
  * multiple of the measurement period.
  *  - Each measurement triggers the measurements generation and raw data output.
  *  - The navRate value defines that every nth measurement triggers a navigation
  *    epoch.
  *  - The update rate has a direct influence on the power consumption. The more
  *    fixes that are required, the more CPU power and communication resources
  *    are required.
  *  - For most applications a 1 Hz update rate would be sufficient.
  *  - When using Power Save Mode, measurement and navigation rate can differ from
  *    the values configured here
 */
typedef struct ublox_msgs__msg__CfgRATE
{
  /// Measurement Rate, GPS measurements are
  /// taken every measRate milliseconds
  uint16_t meas_rate;
  /// Navigation Rate, in number of measurement
  /// cycles. On u-blox 5 and u-blox 6, this parameter
  /// cannot be changed, and always equals 1.
  uint16_t nav_rate;
  /// The time system to which measurements are aligned
  uint16_t time_ref;
} ublox_msgs__msg__CfgRATE;

// Struct for a sequence of ublox_msgs__msg__CfgRATE.
typedef struct ublox_msgs__msg__CfgRATE__Sequence
{
  ublox_msgs__msg__CfgRATE * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ublox_msgs__msg__CfgRATE__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_RATE__STRUCT_H_
