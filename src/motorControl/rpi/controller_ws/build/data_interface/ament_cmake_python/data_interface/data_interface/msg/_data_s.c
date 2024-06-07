// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from data_interface:msg/Data.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "data_interface/msg/detail/data__struct.h"
#include "data_interface/msg/detail/data__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__joy__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__joy__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__image__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__image__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool data_interface__msg__data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[30];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("data_interface.msg._data.Data", full_classname_dest, 29) == 0);
  }
  data_interface__msg__Data * ros_message = _ros_message;
  {  // gamepad
    PyObject * field = PyObject_GetAttrString(_pymsg, "gamepad");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__joy__convert_from_py(field, &ros_message->gamepad)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // cam0
    PyObject * field = PyObject_GetAttrString(_pymsg, "cam0");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__image__convert_from_py(field, &ros_message->cam0)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // cam1
    PyObject * field = PyObject_GetAttrString(_pymsg, "cam1");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__image__convert_from_py(field, &ros_message->cam1)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // data_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "data_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->data_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // auto_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "auto_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->auto_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // steering
    PyObject * field = PyObject_GetAttrString(_pymsg, "steering");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->steering = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // throttle
    PyObject * field = PyObject_GetAttrString(_pymsg, "throttle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->throttle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * data_interface__msg__data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Data */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("data_interface.msg._data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Data");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  data_interface__msg__Data * ros_message = (data_interface__msg__Data *)raw_ros_message;
  {  // gamepad
    PyObject * field = NULL;
    field = sensor_msgs__msg__joy__convert_to_py(&ros_message->gamepad);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "gamepad", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cam0
    PyObject * field = NULL;
    field = sensor_msgs__msg__image__convert_to_py(&ros_message->cam0);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "cam0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cam1
    PyObject * field = NULL;
    field = sensor_msgs__msg__image__convert_to_py(&ros_message->cam1);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "cam1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // data_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->data_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "data_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // auto_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->auto_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "auto_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steering
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->steering);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steering", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // throttle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->throttle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "throttle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
