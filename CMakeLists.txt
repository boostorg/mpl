# Copyright Louis Dionne 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

##############################################################################
# Setup project
##############################################################################
cmake_minimum_required(VERSION 3.0)
project(Boost.MPL CXX)
enable_testing()


##############################################################################
# Setup compiler flags (more can be set on a per-target basis or in subdirectories)
##############################################################################
include(CheckCXXCompilerFlag)
macro(boost_mpl_append_flag testname flag)
    check_cxx_compiler_flag(${flag} ${testname})
    if (${testname})
        add_compile_options(${flag})
    endif()
endmacro()

boost_mpl_append_flag(BOOST_MPL_HAS_FTEMPLATE_BACKTRACE_LIMIT  -ftemplate-backtrace-limit=0)
boost_mpl_append_flag(BOOST_MPL_HAS_PEDANTIC                   -pedantic)
boost_mpl_append_flag(BOOST_MPL_HAS_W                          -W)
boost_mpl_append_flag(BOOST_MPL_HAS_WALL                       -Wall)
boost_mpl_append_flag(BOOST_MPL_HAS_WEXTRA                     -Wextra)


##############################################################################
# Search for Boost.
#
# Since Boost is not CMake-ified as of writing this, we need to look for the
# whole of Boost instead of only fetching the few dependencies of MPL.
##############################################################################
find_package(Boost REQUIRED)


##############################################################################
# Setup subdirectories.
##############################################################################
add_subdirectory(test)


##############################################################################
# Setup the 'install' target.
# This copies the whole content of include/ to ${CMAKE_INSTALL_PREFIX}.
##############################################################################
install(DIRECTORY include/boost DESTINATION include
        PATTERN ".DS_Store" EXCLUDE)
