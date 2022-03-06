cmake_minimum_required(VERSION 3.2)
project( IntervalCounter )
include_directories(
  include
)
add_executable( interval_counter
    src/interval_counter.cpp
    include/argparse.hpp
)
target_link_libraries( interval_counter )

