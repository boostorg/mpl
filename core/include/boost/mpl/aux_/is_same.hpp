#ifndef BOOST_MPL_AUX_IS_SAME_HPP_INCLUDED
#define BOOST_MPL_AUX_IS_SAME_HPP_INCLUDED

// Copyright Andrey Semashev 2014
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <boost/mpl/bool.hpp>

namespace boost { namespace mpl { namespace aux {

template< typename T, typename U >
struct is_same : mpl::false_ {};

template< typename T >
struct is_same< T, T > : mpl::true_ {};

}}}

#endif // BOOST_MPL_AUX_IS_SAME_HPP_INCLUDED
