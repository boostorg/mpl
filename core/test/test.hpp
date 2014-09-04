
#ifndef BOOST_MPL_TEST_TEST_HPP_INCLUDED
#define BOOST_MPL_TEST_TEST_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include "test/test_case.hpp"
#include "test/data.hpp"
#include "test/assert.hpp"
#include <boost/core/lightweight_test.hpp>

int main()
{
    return boost::report_errors();
}

using namespace boost;
using namespace mpl;

#endif // BOOST_MPL_TEST_TEST_HPP_INCLUDED
