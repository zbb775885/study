/*
 * @Copyright (c) 2014-2020 zhoubo :  All rights reserved.
 * @Description:
 * @Author: 周波
 * @Date: 2021-02-28 12:21:36
 * @LastEditors: 周波
 * @LastEditTime: 2021-02-28 12:21:37
 * @FilePath: /c++/template.cc
 */
#include <iostream>
#include <stdint.h>
#include <vector>
#include <numeric>

template <typename T>
auto sum(T &a, T &b)
{
    std::cout << "&" << a + b << std::endl;
    //static decltype(a + b) c = a + b;

    return a + b;
}

template <typename T>
auto sum(T &&a, T &&b)
{
    std::cout << "&&" << a + b << std::endl;
    return a + b;
}

const char *sum(const char *a, const char *b)
{
    std::cout << "&&111" << std::endl;

    return a;
}

int32_t main(int32_t argc, char **args)
{
    int32_t a = 1;
    int32_t b = 2;

    sum(1, 2);
    sum(a, b);
    sum(1.5, 6.7);
    char str1[] = "abc";
    char str2[] = "abc";

    sum("abc", "abc");
    std::cout << "sum is " << sum(1, 2) << std::endl;
    std::cout << "sum is " << sum(a, b) << std::endl;

    // std::cout << "sum is " << sum(1.5, 6.7) << std::endl;

    return 0;
}
