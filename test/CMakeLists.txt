# Copyright Louis Dionne 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

file(GLOB UNIT_TESTS
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "*.cpp" "aux_/*.cpp" "aux_/preprocessor/*.cpp"
)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

foreach(test IN LISTS UNIT_TESTS)
    get_filename_component(target ${test} NAME_WE)
    add_executable(${target} ${CMAKE_CURRENT_SOURCE_DIR}/${test})
    add_test(${target} ${target})
endforeach()
