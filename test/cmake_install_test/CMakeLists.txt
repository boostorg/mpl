# Copyright 2018 Peter Dimov
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.5...3.31)

project(cmake_install_test LANGUAGES CXX)

if(BOOST_CI_INSTALLED_BY STREQUAL "B2")

  find_package(Boost REQUIRED)

  add_library(Boost::mpl INTERFACE IMPORTED)
  set_property(TARGET Boost::mpl APPEND PROPERTY INTERFACE_LINK_LIBRARIES Boost::headers)

else()

  find_package(boost_mpl REQUIRED)

endif()

add_executable(main main.cpp)
target_link_libraries(main Boost::mpl)

enable_testing()
add_test(NAME main COMMAND main)

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure -C $<CONFIG>)
