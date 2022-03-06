# cpp_for_python_tests
C++ tests

Documentation on how to create a c extension module for python can be found [here](https://docs.python.org/3/extending/extending.html) and [here](https://docs.python.org/3/extending/building.html#building)

## Usage
First create a virtualenv and enter it. Then:
```
python setup.py build && python setup.py install && python tests/test.py
```
