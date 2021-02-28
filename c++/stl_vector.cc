/*
 * @Copyright (c) 2014-2020 zhoubo :  All rights reserved.
 * @Description:
 * @Author: 周波
 * @Date: 2021-02-28 12:24:10
 * @LastEditors: 周波
 * @LastEditTime: 2021-02-28 18:48:06
 * @FilePath: /c++/stl_vector.cc
 */
#include <iostream>
#include <stdint.h>
#include <vector>
#include <numeric>
#include <iterator>
#include <list>

using namespace std;

int32_t main(int32_t argc, char **args)
{
    std::list<const char *> list = { "abc" };
    std::vector<string> vec_str;

    ///设置vector的值
    vec_str.assign(list.begin(), list.end());
    std::cout << vec_str[0] << "  size  " << vec_str.size() << std::endl;
    std::cout << "begin " << &*vec_str.begin() << std::endl;

    ///reserve放大后空间会变化，iterator也会发生变化
    vec_str.reserve(2);
    std::cout << "rev begin " << &*vec_str.begin() << std::endl;
    std::cout << "2rev begin " << &*vec_str.begin() << std::endl;

    std::cout << vec_str[0] << "  size  " << vec_str.size() << std::endl;

    vec_str.assign(10, "deef");
    std::cout << vec_str[0] << "  size  " << vec_str.size() << std::endl;

    vec_str.assign({ "fdaf", "ddd" });
    std::cout << vec_str[0] << "  size  " << vec_str.size() << std::endl;
    std::pair<int, int> a;
    ///访问第一个元素
    std::cout << vec_str[0] << " " << vec_str.at(0) << " " << std::endl;
    std::cout << vec_str.front() << " " << *vec_str.begin() << " " << std::endl;

    return 0;
}
