from distutils.core import Extension, setup
# from setuptools import Extension, setup

inhouse_module = Extension("inhouse", sources=["inhouse/inhouse.c"])

setup(
    name="inhouse",
    version="0.0.1",
    description="Inhouse package",
    ext_modules=[inhouse_module])
