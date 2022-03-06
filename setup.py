from distutils.core import Extension, setup

module1 = Extension("mycounter", sources=["interval_counter/interval_counter.c"])

setup(name="mycounter",
      version="1.0.0",
      description="My test package",
      ext_modules=[module1])
