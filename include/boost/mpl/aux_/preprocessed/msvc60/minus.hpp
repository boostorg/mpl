
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//

// Preprocessed version of "boost/mpl/minus.hpp" header
// -- DO NOT modify by hand!

namespace boost { namespace mpl {

template<
      typename Tag1
    , typename Tag2

    , BOOST_MPL_AUX_NTTP_DECL(int, tag1_) = BOOST_MPL_AUX_MSVC_VALUE_WKND(Tag1)::value
    , BOOST_MPL_AUX_NTTP_DECL(int, tag2_) = BOOST_MPL_AUX_MSVC_VALUE_WKND(Tag2)::value
    >
struct minus_impl
    : if_c<
          ( tag1_ > tag2_ )

        , aux::cast2nd_impl< minus_impl< Tag1,Tag2 >,Tag1, Tag2 >
        , aux::cast1st_impl< minus_impl< Tag1,Tag2 >,Tag1, Tag2 >
        >
{
};

/// for Digital Mars C++/compilers with no CTPS support
template<> struct minus_impl< na,na >
{
    template< typename U1, typename U2 > struct apply
    {
        typedef apply type;
        enum { value = 0 };
    };
};

template<> struct minus_impl< na,integral_c_tag >
{
    template< typename U1, typename U2 > struct apply
    {
        typedef apply type;
        enum { value = 0 };
    };
};

template<> struct minus_impl< integral_c_tag,na >
{
    template< typename U1, typename U2 > struct apply
    {
        typedef apply type;
        enum { value = 0 };
    };
};

template< typename T > struct minus_tag
{
    typedef typename T::tag type;
};

template<
      typename BOOST_MPL_AUX_NA_PARAM(N1)
    , typename BOOST_MPL_AUX_NA_PARAM(N2)
    >
struct minus
    : aux::msvc_eti_base< typename apply_wrap2<
          minus_impl<
              typename minus_tag<N1>::type
            , typename minus_tag<N2>::type
            >
        , N1
        , N2
        >::type >::type

{
    BOOST_MPL_AUX_LAMBDA_SUPPORT(2, minus, (N1, N2))

};

BOOST_MPL_AUX_NA_SPEC2(2, 2, minus)

}}

namespace boost { namespace mpl {

namespace aux {
template< typename T, T n1, T n2 >
struct msvc_minus_impl
{
  enum msvc_wknd { value = (n1 - n2) };
    typedef integral_c< T,value > type;
};

}

template<>
struct minus_impl< integral_c_tag,integral_c_tag >
{
    template< typename N1, typename N2 > struct apply
        : aux::msvc_minus_impl<
              typename aux::largest_int<
                  typename N1::value_type
                , typename N2::value_type
                >::type
            , N1::value
            , N2::value
            >::type

    {
    };
};

}}