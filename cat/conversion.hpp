//
// Created by key on 2017/12/1.
//

#ifndef CAT_CONVERSION_HPP
#define CAT_CONVERSION_HPP

#include <string>

namespace cat
{
    template <typename T>
    int toInt(const T &c_str, int base = 10)
    {
        return std::stoi(c_str, 0, base);
    }

    template <typename T>
    unsigned int toUInt(const T &c_str, int base = 10)
    {
        int num = toInt(c_str, base);
        return static_cast<unsigned int>(num);
    }

    template <typename T>
    short toShort(const T &c_str, int base = 10)
    {
        int num = toInt(c_str, base);
        return static_cast<short>(num);
    }

    template <typename T>
    unsigned short toUShort(const T &c_str, int base = 10)
    {
        short num = toShort(c_str, base);
        return static_cast<unsigned short>(num);
    }

    template <typename T>
    long toLong(const T &c_str, int base = 10)
    {
        return std::stol(c_str, 0, base);
    }

    template <typename T>
    long toULong(const T &c_str, int base = 10)
    {
        return std::stoul(c_str, 0, base);
    }

    template <typename T>
    long long toLongLong(const T &c_str, int base = 10)
    {
        return std::stoll(c_str, 0, base);
    }

    template <typename T>
    long toULongLong(const T &c_str, int base = 10)
    {
        return std::stoull(c_str, 0, base);
    }

    template <typename T>
    int toFloat(const T &c_str)
    {
        return std::stof(c_str);
    }

    template <typename T>
    int toDouble(const T &c_str)
    {
        return std::stod(c_str);
    }

}

#endif //CAT_CONVERSION_HPP
