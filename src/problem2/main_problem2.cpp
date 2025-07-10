// src/test_problem2.cpp
#include <iostream>
#include "problem2.h"

int main()
{
    int x = 3, y = 4;
    int result = add(x, y);
    std::cout << "测试题目二：add(" << x << ", " << y << ") = " << result << std::endl;

    if (result == 7)
    {
        std::cout << "测试通过！" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "测试失败！" << std::endl;
        return 1;
    }
}
