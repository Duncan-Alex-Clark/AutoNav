# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/RxmRAW.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RxmRAW(type):
    """Metaclass of message 'RxmRAW'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 2,
        'MESSAGE_ID': 16,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ublox_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ublox_msgs.msg.RxmRAW')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rxm_raw
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rxm_raw
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rxm_raw
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rxm_raw
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rxm_raw

            from ublox_msgs.msg import RxmRAWSV
            if RxmRAWSV.__class__._TYPE_SUPPORT is None:
                RxmRAWSV.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_RxmRAW.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_RxmRAW.__constants['MESSAGE_ID']


class RxmRAW(metaclass=Metaclass_RxmRAW):
    """
    Message class 'RxmRAW'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_rcv_tow',
        '_week',
        '_num_sv',
        '_reserved1',
        '_sv',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'rcv_tow': 'int32',
        'week': 'int16',
        'num_sv': 'uint8',
        'reserved1': 'uint8',
        'sv': 'sequence<ublox_msgs/RxmRAWSV>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['ublox_msgs', 'msg'], 'RxmRAWSV')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.rcv_tow = kwargs.get('rcv_tow', int())
        self.week = kwargs.get('week', int())
        self.num_sv = kwargs.get('num_sv', int())
        self.reserved1 = kwargs.get('reserved1', int())
        self.sv = kwargs.get('sv', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.rcv_tow != other.rcv_tow:
            return False
        if self.week != other.week:
            return False
        if self.num_sv != other.num_sv:
            return False
        if self.reserved1 != other.reserved1:
            return False
        if self.sv != other.sv:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def rcv_tow(self):
        """Message field 'rcv_tow'."""
        return self._rcv_tow

    @rcv_tow.setter
    def rcv_tow(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'rcv_tow' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'rcv_tow' field must be an integer in [-2147483648, 2147483647]"
        self._rcv_tow = value

    @builtins.property
    def week(self):
        """Message field 'week'."""
        return self._week

    @week.setter
    def week(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'week' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'week' field must be an integer in [-32768, 32767]"
        self._week = value

    @builtins.property
    def num_sv(self):
        """Message field 'num_sv'."""
        return self._num_sv

    @num_sv.setter
    def num_sv(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'num_sv' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num_sv' field must be an unsigned integer in [0, 255]"
        self._num_sv = value

    @builtins.property
    def reserved1(self):
        """Message field 'reserved1'."""
        return self._reserved1

    @reserved1.setter
    def reserved1(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'reserved1' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'reserved1' field must be an unsigned integer in [0, 255]"
        self._reserved1 = value

    @builtins.property
    def sv(self):
        """Message field 'sv'."""
        return self._sv

    @sv.setter
    def sv(self, value):
        if self._check_fields:
            from ublox_msgs.msg import RxmRAWSV
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, RxmRAWSV) for v in value) and
                 True), \
                "The 'sv' field must be a set or sequence and each value of type 'RxmRAWSV'"
        self._sv = value
