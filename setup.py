from distutils.core import Extension, setup
# from setuptools import Extension, setup

counter_module = Extension("mycounter", sources=["interval_counter/interval_counter.c"])

setup(
    name="mycounter",
    version="0.0.1",
    description="Interval counter package",
    ext_modules=[counter_module])
