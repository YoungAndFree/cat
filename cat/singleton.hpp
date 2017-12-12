//
// Created by key on 2017/12/8.
//

#ifndef CAT_SINGLETON_HPP
#define CAT_SINGLETON_HPP

#include <boost/noncopyable.hpp>
#include <memory>
#include <mutex>

namespace cat
{
    template <typename T>
    class singleton : public boost::noncopyable
    {
        singleton(){}

    public:
        ~singleton(){}

        static std::shared_ptr<T> instance()
        {
            static std::once_flag oc;//用于call_once的局部静态变量
            std::call_once(oc, [&] {  sp_instance.reset(new T); });//多线程下确保只调用一次
            return sp_instance;
        }

    private:
        static std::shared_ptr<T>       sp_instance;
    };

    template <typename T>
    std::shared_ptr<T>  singleton<T>::sp_instance = nullptr;
}

#endif //CAT_SINGLETON_HPP
