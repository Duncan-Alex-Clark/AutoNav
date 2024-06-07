// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from data_interface:msg/Data.idl
// generated code does not contain a copyright notice

#include "data_interface/msg/detail/data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_data_interface
const rosidl_type_hash_t *
data_interface__msg__Data__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xbf, 0xb5, 0xc1, 0xe3, 0xfe, 0x0b, 0x3a, 0xcb,
      0x3f, 0xbd, 0xbd, 0x7b, 0xb6, 0xb0, 0x8e, 0x6b,
      0x4c, 0xf0, 0x2d, 0x06, 0x70, 0x8a, 0xb3, 0xe4,
      0xd6, 0x3d, 0x4f, 0xdf, 0x04, 0xbe, 0x40, 0x73,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/header__functions.h"
#include "sensor_msgs/msg/detail/image__functions.h"
#include "sensor_msgs/msg/detail/joy__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t sensor_msgs__msg__Image__EXPECTED_HASH = {1, {
    0xd3, 0x1d, 0x41, 0xa9, 0xa4, 0xc4, 0xbc, 0x8e,
    0xae, 0x9b, 0xe7, 0x57, 0xb0, 0xbe, 0xed, 0x30,
    0x65, 0x64, 0xf7, 0x52, 0x6c, 0x88, 0xea, 0x6a,
    0x45, 0x88, 0xfb, 0x95, 0x82, 0x52, 0x7d, 0x47,
  }};
static const rosidl_type_hash_t sensor_msgs__msg__Joy__EXPECTED_HASH = {1, {
    0x0d, 0x35, 0x6c, 0x79, 0xca, 0xd3, 0x40, 0x1e,
    0x35, 0xff, 0xeb, 0x75, 0xa9, 0x6a, 0x96, 0xe0,
    0x8b, 0xe3, 0xef, 0x89, 0x6b, 0x8b, 0x83, 0x84,
    0x1d, 0x73, 0xe8, 0x90, 0x98, 0x93, 0x72, 0xc5,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char data_interface__msg__Data__TYPE_NAME[] = "data_interface/msg/Data";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char sensor_msgs__msg__Image__TYPE_NAME[] = "sensor_msgs/msg/Image";
static char sensor_msgs__msg__Joy__TYPE_NAME[] = "sensor_msgs/msg/Joy";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char data_interface__msg__Data__FIELD_NAME__gamepad[] = "gamepad";
static char data_interface__msg__Data__FIELD_NAME__cam0[] = "cam0";
static char data_interface__msg__Data__FIELD_NAME__cam1[] = "cam1";
static char data_interface__msg__Data__FIELD_NAME__data_active[] = "data_active";
static char data_interface__msg__Data__FIELD_NAME__auto_active[] = "auto_active";
static char data_interface__msg__Data__FIELD_NAME__steering[] = "steering";
static char data_interface__msg__Data__FIELD_NAME__throttle[] = "throttle";
static char data_interface__msg__Data__FIELD_NAME__latitude[] = "latitude";
static char data_interface__msg__Data__FIELD_NAME__longitude[] = "longitude";

static rosidl_runtime_c__type_description__Field data_interface__msg__Data__FIELDS[] = {
  {
    {data_interface__msg__Data__FIELD_NAME__gamepad, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {sensor_msgs__msg__Joy__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {data_interface__msg__Data__FIELD_NAME__cam0, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {sensor_msgs__msg__Image__TYPE_NAME, 21, 21},
    },
    {NULL, 0, 0},
  },
  {
    {data_interface__msg__Data__FIELD_NAME__cam1, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {sensor_msgs__msg__Image__TYPE_NAME, 21, 21},
    },
    {NULL, 0, 0},
  },
  {
    {data_interface__msg__Data__FIELD_NAME__data_active, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {data_interface__msg__Data__FIELD_NAME__auto_active, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {data_interface__msg__Data__FIELD_NAME__steering, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {data_interface__msg__Data__FIELD_NAME__throttle, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {data_interface__msg__Data__FIELD_NAME__latitude, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {data_interface__msg__Data__FIELD_NAME__longitude, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription data_interface__msg__Data__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__Image__TYPE_NAME, 21, 21},
    {NULL, 0, 0},
  },
  {
    {sensor_msgs__msg__Joy__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
data_interface__msg__Data__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {data_interface__msg__Data__TYPE_NAME, 23, 23},
      {data_interface__msg__Data__FIELDS, 9, 9},
    },
    {data_interface__msg__Data__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__Image__EXPECTED_HASH, sensor_msgs__msg__Image__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = sensor_msgs__msg__Image__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&sensor_msgs__msg__Joy__EXPECTED_HASH, sensor_msgs__msg__Joy__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = sensor_msgs__msg__Joy__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "sensor_msgs/Joy gamepad\n"
  "sensor_msgs/Image cam0\n"
  "sensor_msgs/Image cam1\n"
  "bool data_active\n"
  "bool auto_active\n"
  "float32 steering\n"
  "float32 throttle\n"
  "float32 latitude\n"
  "float32 longitude";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
data_interface__msg__Data__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {data_interface__msg__Data__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 173, 173},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
data_interface__msg__Data__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *data_interface__msg__Data__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *sensor_msgs__msg__Image__get_individual_type_description_source(NULL);
    sources[3] = *sensor_msgs__msg__Joy__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
