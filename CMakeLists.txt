cmake_minimum_required(VERSION 3.5)
project(boost-mpl)

add_library(boost_mpl INTERFACE)
add_library(Boost::mpl ALIAS boost_mpl)

target_include_directories(boost_mpl INTERFACE include)

target_link_libraries(boost_mpl
	INTERFACE
		Boost::config
		Boost::core
		Boost::predef
		Boost::preprocessor
		Boost::static_assert
		Boost::type_traits
		Boost::utility
)

