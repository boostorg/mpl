
// Copyright Bruno Dutra 2015
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#define BOOST_MPL_LIMIT_METAFUNCTION_ARITY 15
#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS

#include <boost/mpl/logical.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/apply.hpp>

#include <boost/mpl/aux_/test.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/inc.hpp>
#include <boost/preprocessor/repeat_from_to.hpp>
#include <boost/preprocessor/enum_params.hpp>
#include <boost/preprocessor/enum_shifted_params.hpp>
#include <boost/preprocessor/facilities/intercept.hpp>

#define TEST_N_ARY(unused1, N, unused2) \
    struct BOOST_PP_CAT(_, BOOST_PP_CAT(N, _ary)) \
    { \
        MPL_ASSERT(( \
                apply< \
                    and_<BOOST_PP_ENUM_SHIFTED_PARAMS(BOOST_PP_INC(N), _)>, \
                    BOOST_PP_ENUM_PARAMS(N, true_ BOOST_PP_INTERCEPT) \
                > \
            )); \
    }; \
/**/

MPL_TEST_CASE()
{
    BOOST_PP_REPEAT_FROM_TO(
            2,
            BOOST_PP_INC(BOOST_MPL_LIMIT_METAFUNCTION_ARITY),
            TEST_N_ARY,
            _
        )
}
