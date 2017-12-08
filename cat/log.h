//
// Created by key on 2017/12/8.
//

#ifndef CAT_LOG_H
#define CAT_LOG_H

#include <boost/noncopyable.hpp>
#include <memory>

namespace key
{
    class log : public boost::noncopyable
    {
        log(){}
        ~log(){}

    public:
        typedef std::shared_ptr<log> log_ptr;

        static log_ptr instance()
        {
            if (!sp_log)
            {
                sp_log.reset(new log);
            }

            return sp_log;
        }

    private:
        static log_ptr      sp_log;
    };
}

#endif //CAT_LOG_H
