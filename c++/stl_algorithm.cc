/*
 * @Copyright (c) 2014-2020 zhoubo :  All rights reserved.
 * @Description:
 * @Author: 周波
 * @Date: 2021-02-28 12:24:10
 * @LastEditors: 周波
 * @LastEditTime: 2021-02-28 20:41:40
 * @FilePath: /c++/stl_algorithm.cc
 */
#include <iostream>
#include <stdint.h>
#include <vector>
#include <numeric>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

template <typename Tp1, typename Tp2>
struct equal_my {
    public:
    auto operator()(const Tp1 &val1, const Tp2 &val2)
    {
        return val1 == val2;
    };
};

int32_t main(int32_t argc, char **args)
{
    ///std::count用法，原理为for循环查找value
    std::vector<int32_t> vector_count = { 1, 2, 3, 4, 5 };
    std::cout << "vector_count: " << std::count(std::begin(vector_count), std::end(vector_count), 1) << std::endl;

    std::list<char> list_count;
    for (auto &ch : "abc") {
        list_count.push_back(ch);
    }
    std::cout << "list_count: " << std::count(std::begin(list_count), std::end(list_count), 'e') << std::endl;

    ///std::find用法,原理为for循环并利用equal仿函数对应==来比较是否相等
    std::vector<int32_t> vector_find = { 1, 2, 3, 4, 5 };
    std::cout << "vector_find:" << &*std::find(std::begin(vector_find), std::end(vector_find), 1) << std::endl;

    ///std::accumulate用法，原理为第3个参数为初始值，for循环init+=val,如果第四个参数存在那么为init = ops(init,val)
    ///所有的value必须支持ops对应的操作,默认为+
    std::vector<int32_t> vector_accu = { 1, 2, 3, 4, 5 };
    std::cout << "vector_accu: " << std::accumulate(std::begin(vector_accu), std::end(vector_accu), 0) << std::endl;
    std::cout << "vector_accu mul: " << std::accumulate(std::begin(vector_accu), std::end(vector_accu), 0, std::multiplies<int32_t>()) << std::endl;
    std::cout << "vector_accu div: " << std::accumulate(std::begin(vector_accu), std::end(vector_accu), 0, std::divides<int32_t>()) << std::endl;

    std::vector<double> vector_accu_v1 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    std::cout << "vector_accu_v1: " << std::accumulate(std::begin(vector_accu_v1), std::end(vector_accu_v1), 0.0) << std::endl;
    std::cout << "vector_accu_v1 mul: " << std::accumulate(std::begin(vector_accu_v1), std::end(vector_accu_v1), 0.0, std::multiplies<double>()) << std::endl;
    std::cout << "vector_accu_v1 div: " << std::accumulate(std::begin(vector_accu_v1), std::end(vector_accu_v1), 0.0, std::divides<double>()) << std::endl;

    ///std::equal,只接受迭代器参数，equal第一个序列的参数范围和第二个序列的参数要一致
    std::vector<std::string> vector_equal = { "12", "23", "34" };
    std::list<const char *> list_equal = { "12", "23", "34" };

    std::cout << "vector_equal: " << std::equal(std::begin(vector_equal), std::end(vector_equal), list_equal.begin()) << std::endl;
    std::cout << "vector_equal: " << std::equal(std::begin(vector_equal), std::end(vector_equal), list_equal.begin()) << std::endl;
    std::cout << "vector_equal: " << std::equal(std::begin(vector_equal), std::end(vector_equal), list_equal.begin()) << std::endl;
    std::cout << "vector_equal: " << std::equal(std::begin(vector_equal), std::end(vector_equal), list_equal.begin(), equal_my<std::string, const char *>()) << std::endl;

    return 0;
}
