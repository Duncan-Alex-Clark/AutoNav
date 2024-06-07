// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from data_interface:msg/Data.idl
// generated code does not contain a copyright notice
#include "data_interface/msg/detail/data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `gamepad`
#include "sensor_msgs/msg/detail/joy__functions.h"
// Member `cam0`
// Member `cam1`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
data_interface__msg__Data__init(data_interface__msg__Data * msg)
{
  if (!msg) {
    return false;
  }
  // gamepad
  if (!sensor_msgs__msg__Joy__init(&msg->gamepad)) {
    data_interface__msg__Data__fini(msg);
    return false;
  }
  // cam0
  if (!sensor_msgs__msg__Image__init(&msg->cam0)) {
    data_interface__msg__Data__fini(msg);
    return false;
  }
  // cam1
  if (!sensor_msgs__msg__Image__init(&msg->cam1)) {
    data_interface__msg__Data__fini(msg);
    return false;
  }
  // data_active
  // auto_active
  // steering
  // throttle
  // latitude
  // longitude
  return true;
}

void
data_interface__msg__Data__fini(data_interface__msg__Data * msg)
{
  if (!msg) {
    return;
  }
  // gamepad
  sensor_msgs__msg__Joy__fini(&msg->gamepad);
  // cam0
  sensor_msgs__msg__Image__fini(&msg->cam0);
  // cam1
  sensor_msgs__msg__Image__fini(&msg->cam1);
  // data_active
  // auto_active
  // steering
  // throttle
  // latitude
  // longitude
}

bool
data_interface__msg__Data__are_equal(const data_interface__msg__Data * lhs, const data_interface__msg__Data * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // gamepad
  if (!sensor_msgs__msg__Joy__are_equal(
      &(lhs->gamepad), &(rhs->gamepad)))
  {
    return false;
  }
  // cam0
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->cam0), &(rhs->cam0)))
  {
    return false;
  }
  // cam1
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->cam1), &(rhs->cam1)))
  {
    return false;
  }
  // data_active
  if (lhs->data_active != rhs->data_active) {
    return false;
  }
  // auto_active
  if (lhs->auto_active != rhs->auto_active) {
    return false;
  }
  // steering
  if (lhs->steering != rhs->steering) {
    return false;
  }
  // throttle
  if (lhs->throttle != rhs->throttle) {
    return false;
  }
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  return true;
}

bool
data_interface__msg__Data__copy(
  const data_interface__msg__Data * input,
  data_interface__msg__Data * output)
{
  if (!input || !output) {
    return false;
  }
  // gamepad
  if (!sensor_msgs__msg__Joy__copy(
      &(input->gamepad), &(output->gamepad)))
  {
    return false;
  }
  // cam0
  if (!sensor_msgs__msg__Image__copy(
      &(input->cam0), &(output->cam0)))
  {
    return false;
  }
  // cam1
  if (!sensor_msgs__msg__Image__copy(
      &(input->cam1), &(output->cam1)))
  {
    return false;
  }
  // data_active
  output->data_active = input->data_active;
  // auto_active
  output->auto_active = input->auto_active;
  // steering
  output->steering = input->steering;
  // throttle
  output->throttle = input->throttle;
  // latitude
  output->latitude = input->latitude;
  // longitude
  output->longitude = input->longitude;
  return true;
}

data_interface__msg__Data *
data_interface__msg__Data__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  data_interface__msg__Data * msg = (data_interface__msg__Data *)allocator.allocate(sizeof(data_interface__msg__Data), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(data_interface__msg__Data));
  bool success = data_interface__msg__Data__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
data_interface__msg__Data__destroy(data_interface__msg__Data * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    data_interface__msg__Data__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
data_interface__msg__Data__Sequence__init(data_interface__msg__Data__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  data_interface__msg__Data * data = NULL;

  if (size) {
    data = (data_interface__msg__Data *)allocator.zero_allocate(size, sizeof(data_interface__msg__Data), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = data_interface__msg__Data__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        data_interface__msg__Data__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
data_interface__msg__Data__Sequence__fini(data_interface__msg__Data__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      data_interface__msg__Data__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

data_interface__msg__Data__Sequence *
data_interface__msg__Data__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  data_interface__msg__Data__Sequence * array = (data_interface__msg__Data__Sequence *)allocator.allocate(sizeof(data_interface__msg__Data__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = data_interface__msg__Data__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
data_interface__msg__Data__Sequence__destroy(data_interface__msg__Data__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    data_interface__msg__Data__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
data_interface__msg__Data__Sequence__are_equal(const data_interface__msg__Data__Sequence * lhs, const data_interface__msg__Data__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!data_interface__msg__Data__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
data_interface__msg__Data__Sequence__copy(
  const data_interface__msg__Data__Sequence * input,
  data_interface__msg__Data__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(data_interface__msg__Data);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    data_interface__msg__Data * data =
      (data_interface__msg__Data *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!data_interface__msg__Data__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          data_interface__msg__Data__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!data_interface__msg__Data__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
