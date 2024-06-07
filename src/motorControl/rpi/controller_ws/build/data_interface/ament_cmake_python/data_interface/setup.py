from setuptools import find_packages
from setuptools import setup

setup(
    name='data_interface',
    version='0.0.0',
    packages=find_packages(
        include=('data_interface', 'data_interface.*')),
)
