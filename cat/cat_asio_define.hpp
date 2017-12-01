//
// Created by cat on 2017/11/30.
//

#ifndef CAT_ASIO_DEFINE_HPP
#define CAT_ASIO_DEFINE_HPP

#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>

#ifdef WIN32
#include <windows.h>
#endif

namespace cat
{
    typedef boost::system::error_code			        error_code;
    typedef boost::asio::io_service::work               work_type;
}

#endif //KEY_ASIO_DEFINE_HPP
