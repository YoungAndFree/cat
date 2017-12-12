//
// Created by key on 2017/12/11.
//

#ifndef CAT_OBJECT_HPP
#define CAT_OBJECT_HPP

#include <memory>
#include <boost/noncopyable.hpp>

namespace cat
{
    class noncopyable : public std::enable_shared_from_this<noncopyable>, boost::noncopyable
    {
    protected:
        noncopyable(){}

        template <typename T>
        std::shared_ptr<T> ptr_cast(std::shared_ptr<noncopyable> sp)
        {
            return std::dynamic_pointer_cast<T>(sp);
        }

        ///子类中shared_from_this()返回的是shared_ptr<noncopyable>
        ///借助ptr_cast转换成实际的子类类型
        ///\return 子类的shared_ptr
        template <typename T>
        std::shared_ptr<T> ptr_this()
        {
            auto sp = shared_from_this();
            return ptr_cast<T>(sp);
        }

    public:
        virtual ~noncopyable(){}
    };

    class cloneable : public noncopyable
    {
    protected:
        cloneable(){}
        typedef std::shared_ptr<cloneable> data_ptr;

    public:
        virtual ~cloneable(){}

    public:
        template <typename T>
        std::shared_ptr<T> clone()
        {
            std::shared_ptr<T> p(new T);
            if (copy(p, ptr_this<cloneable>()));
            {
                return p;
            }
            return nullptr;
        }

    protected:
        virtual bool copy(data_ptr d, const data_ptr &s) = 0;
    };

}
#endif //CAT_OBJECT_HPP
