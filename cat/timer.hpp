//
// Created by cat on 2017/11/29.
//

#ifndef KEY_TIMER_HPP
#define KEY_TIMER_HPP


#include "cat_asio_define.hpp"
#include <memory>
#include <thread>

namespace cat
{
    class timer
    {
        typedef std::function<void(const cat::error_code &)>     handle_type;

    public:
        enum Timer_Type
        {
            Synchronous,
            Asynchronous
        };

        explicit timer(Timer_Type _type) : m_timer(m_io),
                                           m_type(_type),
                                           milliseconds(1),
                                           timer_handle(nullptr)
        {
            init(_type);
        }

        timer(Timer_Type _type,
              const unsigned int &_milliseconds) : m_type(_type),
                                                   milliseconds(_milliseconds),
                                                   m_timer(m_io),
                                                   timer_handle(nullptr)
        {
            init(_type);
        }

        timer(const unsigned int &_milliseconds,
              handle_type &&_handle) : m_type(cat::timer::Asynchronous),
                                       milliseconds(_milliseconds),
                                       m_timer(m_io),
                                       timer_handle(_handle)
        {
            init(cat::timer::Asynchronous);
        }

        void setMilliseconds(const unsigned int &_milliseconds)
        {
            milliseconds = _milliseconds;
        }

        void setHandle(handle_type &&_handle)
        {
            if (m_type == cat::timer::Asynchronous)
            {
                timer_handle = _handle;
            }
        }

        void wait()
        {
            if (m_type == cat::timer::Asynchronous)
            {
                if (timer_handle)
                {
                    m_timer.expires_from_now(std::chrono::milliseconds(milliseconds));
                    m_timer.async_wait(timer_handle);
                }
            }
            else
            {
                m_timer.expires_from_now(std::chrono::milliseconds(milliseconds));
                m_timer.wait();
            }
        }

    private:
        void init(const Timer_Type &_type)
        {
            if (_type == cat::timer::Asynchronous)
            {
                spWork.reset(new work_type(m_io));

                std::thread([&]{
                    m_io.run();
                }).detach();
            }
        }

    private:
        boost::asio::io_service						m_io;
        std::unique_ptr<work_type>					spWork;
        boost::asio::steady_timer                   m_timer;

        unsigned int                                milliseconds;
        Timer_Type                                  m_type;
        handle_type                                 timer_handle;
    };
}


#endif //KEY_TIMER_HPP
