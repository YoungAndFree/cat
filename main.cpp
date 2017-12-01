#include <iostream>
#include "cat/conversion.hpp"

int main()
{
    std::string str = "10";

    int num = cat::toInt(str.c_str(), 16);
    std::cout << num << std::endl;
    return 0;
}