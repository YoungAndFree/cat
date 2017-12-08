//
// Created by key on 2017/12/8.
//

#ifndef CAT_SINGLETON_POOL_HPP
#define CAT_SINGLETON_POOL_HPP

#include "singleton.hpp"
#include <mutex>

namespace key
{
    class singleton_pool : public boost::noncopyable, std::enable_shared_from_this<singleton_pool>
    {
    public:
        typedef std::shared_ptr<singleton_pool> ptr;

        singleton_pool(){}
        ~singleton_pool(){}

        static ptr instance()
        {
            if (!sp_singleton_pool)
            {
                if (!sp_singleton_pool)
                {
                    std::lock_guard<std::mutex> lg(m_mutex);
                    sp_singleton_pool.reset(new singleton_pool);
                }
            }
            return sp_singleton_pool;
        }

    private:
        static ptr          sp_singleton_pool;
        static std::mutex   m_mutex;
    };
}

#endif //CAT_SINGLETON_POOL_HPP
