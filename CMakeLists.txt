cmake_minimum_required(VERSION 3.8)
project(cat)

set(CMAKE_CXX_STANDARD 11)

#*************添加Boost库************************
set(Boost_USE_STATIC_LIBS ON)
set(BOOST_ROOT $ENV{BOOST_HOME})
find_package(Boost COMPONENTS system)
include_directories(${Boost_INCLUDE_DIR})
#***********************************************

set(SOURCE_FILES main.cpp
        cat/timer.hpp
        cat/cat_asio_define.hpp
        cat/cat.h
        cat/conversion.hpp
        cat/singleton.hpp
        cat/cloneable.hpp cat/object_test.h)
add_executable(cat ${SOURCE_FILES})
target_link_libraries(cat ${Boost_LIBRARIES})
if (WIN32)
    target_link_libraries(cat ws2_32)
endif ()
