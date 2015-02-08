
#ifndef BOOST_MPL_AUX_PREPROCESSOR_RANGE_HPP_INCLUDED
#define BOOST_MPL_AUX_PREPROCESSOR_RANGE_HPP_INCLUDED

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

#include <boost/preprocessor/seq/subseq.hpp>
#include <boost/preprocessor/tuple/to_seq.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/preprocessor/punctuation.hpp>
#include <boost/preprocessor/enum_params.hpp>
#include <boost/preprocessor/empty.hpp>

#undef BOOST_MPL_PP_RANGE
#define BOOST_MPL_PP_RANGE(first, length) \
    BOOST_PP_SEQ_SUBSEQ( \
        BOOST_PP_TUPLE_TO_SEQ( \
                BOOST_PP_ADD(first, length), \
                BOOST_PP_LPAREN() \
                BOOST_PP_ENUM_PARAMS(BOOST_PP_ADD(first, length), BOOST_PP_EMPTY()) \
                BOOST_PP_RPAREN() \
        ), \
        first, length \
    ) \
/**/

#endif // BOOST_MPL_AUX_PREPROCESSOR_RANGE_HPP_INCLUDED
