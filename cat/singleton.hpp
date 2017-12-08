//
// Created by key on 2017/12/8.
//

#ifndef CAT_SINGLETON_HPP
#define CAT_SINGLETON_HPP

#include <boost/noncopyable.hpp>
#include <memory>

namespace key
{
    class singleton : public boost::noncopyable
    {
        singleton(){}
        ~singleton(){}

    public:
        typedef std::shared_ptr<singleton> singleton_ptr;

        virtual singleton_ptr instance() = 0;

    };
}

#endif //CAT_SINGLETON_HPP
