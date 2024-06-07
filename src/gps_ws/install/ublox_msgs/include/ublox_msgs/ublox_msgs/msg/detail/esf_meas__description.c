// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ublox_msgs:msg/EsfMEAS.idl
// generated code does not contain a copyright notice

#include "ublox_msgs/msg/detail/esf_meas__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
const rosidl_type_hash_t *
ublox_msgs__msg__EsfMEAS__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xda, 0x11, 0x39, 0x38, 0xb1, 0xcc, 0x55, 0x8d,
      0xd8, 0xd4, 0x57, 0xfd, 0xbe, 0xc2, 0x8b, 0xb7,
      0x1f, 0xe3, 0x79, 0xc7, 0xf3, 0xe5, 0xdc, 0xd0,
      0x23, 0xb0, 0xba, 0x33, 0x2e, 0xb0, 0x77, 0xe7,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ublox_msgs__msg__EsfMEAS__TYPE_NAME[] = "ublox_msgs/msg/EsfMEAS";

// Define type names, field names, and default values
static char ublox_msgs__msg__EsfMEAS__FIELD_NAME__time_tag[] = "time_tag";
static char ublox_msgs__msg__EsfMEAS__FIELD_NAME__flags[] = "flags";
static char ublox_msgs__msg__EsfMEAS__FIELD_NAME__id[] = "id";
static char ublox_msgs__msg__EsfMEAS__FIELD_NAME__data[] = "data";
static char ublox_msgs__msg__EsfMEAS__FIELD_NAME__calib_t_tag[] = "calib_t_tag";

static rosidl_runtime_c__type_description__Field ublox_msgs__msg__EsfMEAS__FIELDS[] = {
  {
    {ublox_msgs__msg__EsfMEAS__FIELD_NAME__time_tag, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ublox_msgs__msg__EsfMEAS__FIELD_NAME__flags, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ublox_msgs__msg__EsfMEAS__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ublox_msgs__msg__EsfMEAS__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ublox_msgs__msg__EsfMEAS__FIELD_NAME__calib_t_tag, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ublox_msgs__msg__EsfMEAS__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ublox_msgs__msg__EsfMEAS__TYPE_NAME, 22, 22},
      {ublox_msgs__msg__EsfMEAS__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# ESF-MEAS (0x10 0x02)\n"
  "# External Sensor Fusion Measurements\n"
  "#\n"
  "# Possible data types for the data field are described in the ESF Measurement\n"
  "# Data section\n"
  "#\n"
  "\n"
  "uint8 CLASS_ID = 16\n"
  "uint8 MESSAGE_ID = 2\n"
  "\n"
  "uint32 time_tag               # Time tag of measurement generated by external\n"
  "                             # sensor\n"
  "\n"
  "uint16 flags                 # Flags. Set all unused bits to zero:\n"
  "uint16 FLAGS_TIME_MARK_SENT_MASK = 3   # Time mark signal was supplied just\n"
  "                                       # prior to sending this message: 0 =\n"
  "uint16 TIME_MARK_NONE = 0\n"
  "uint16 TIME_MARK_EXT0 = 1\n"
  "uint16 TIME_MARK_EXT = 2\n"
  "uint16 FLAGS_TIME_MARK_EDGE = 4        # Trigger on rising (0) or falling\n"
  "                                       # (1) edge of time mark signal\n"
  "uint16 FLAGS_CALIB_T_TAG_VALID = 8     # Calibration time tag available.\n"
  "                                       # Always set to zero.\n"
  "\n"
  "uint16 id                              # Identification number of data provider\n"
  "\n"
  "# Start of repeated block (N times)\n"
  "uint32[] data                # data, see mask below\n"
  "uint32 DATA_FIELD_MASK = 16777215     # data\n"
  "uint32 DATA_TYPE_MASK = 1056964608    # type of data (1..63)\n"
  "uint32 DATA_TYPE_SHIFT = 24\n"
  "uint32 DATA_TYPE_NONE = 0                     # data field contains no data\n"
  "uint32 DATA_TYPE_Z_AXIS_GYRO = 5              # z-axis gyroscope angular rate\n"
  "                                              # [deg/s *2^-12 signed]\n"
  "uint32 DATA_TYPE_WHEEL_TICKS_FRONT_LEFT = 6   # front-left wheel ticks\n"
  "                                              # Bits 0-22: unsigned tick value.\n"
  "                                              # Bit 23: direction indicator\n"
  "                                              # (0=forward, 1=backward)\n"
  "uint32 DATA_TYPE_WHEEL_TICKS_FRONT_RIGHT = 7  # front-right wheel ticks\n"
  "                                              # Bits 0-22: unsigned tick value.\n"
  "                                              # Bit 23: direction indicator\n"
  "                                              # (0=forward, 1=backward)\n"
  "uint32 DATA_TYPE_WHEEL_TICKS_REAR_LEFT = 8    # rear-left wheel ticks\n"
  "                                              # Bits 0-22: unsigned tick value.\n"
  "                                              # Bit 23: direction indicator\n"
  "                                              # (0=forward, 1=backward)\n"
  "uint32 DATA_TYPE_WHEEL_TICKS_REAR_RIGHT = 9   # rear-right wheel ticks\n"
  "                                              # Bits 0-22: unsigned tick value.\n"
  "                                              # Bit 23: direction indicator\n"
  "                                              # (0=forward, 1=backward)\n"
  "uint32 DATA_TYPE_SINGLE_TICK = 10             # single tick (speed tick)\n"
  "                                              # Bits 0-22: unsigned tick value.\n"
  "                                              # Bit 23: direction indicator\n"
  "                                              # (0=forward, 1=backward)\n"
  "uint32 DATA_TYPE_SPEED = 11                   # speed m/s * 1e-3 signed\n"
  "uint32 DATA_TYPE_GYRO_TEMPERATURE = 12        # gyroscope temperature\n"
  "                                              # [deg Celsius * 1e-2 signed]\n"
  "uint32 DATA_TYPE_GYRO_ANG_RATE_Y = 13         # y-axis gyroscope angular rate\n"
  "                                              # [deg/s *2^-12 signed]\n"
  "uint32 DATA_TYPE_GYRO_ANG_RATE_X = 14         # x-axis gyroscope angular rate\n"
  "                                              # [deg/s *2^-12 signed]\n"
  "uint32 DATA_TYPE_ACCELEROMETER_X = 16         # x-axis accelerometer specific\n"
  "                                              # [force m/s^2 *2^-10 signed]\n"
  "uint32 DATA_TYPE_ACCELEROMETER_Y = 17         # y-axis accelerometer specific\n"
  "                                              # [force m/s^2 *2^-10 signed]\n"
  "uint32 DATA_TYPE_ACCELEROMETER_Z = 18         # z-axis accelerometer specific\n"
  "                                              # [force m/s^2 *2^-10 signed]\n"
  "\n"
  "\n"
  "\n"
  "# End of repeated block\n"
  "\n"
  "# Start of optional block (size is either 0 or 1)\n"
  "uint32[] calib_t_tag           # Receiver local time calibrated.\n"
  "                             # This field must not be supplied when\n"
  "                             # calibTtagValid is set to 0 [ms]\n"
  "# End of optional block";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ublox_msgs__msg__EsfMEAS__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ublox_msgs__msg__EsfMEAS__TYPE_NAME, 22, 22},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 4191, 4191},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ublox_msgs__msg__EsfMEAS__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ublox_msgs__msg__EsfMEAS__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
