/*
 * @Copyright (c) 2014-2020 zhoubo :  All rights reserved.
 * @Description:
 * @Author: 周波
 * @Date: 2021-02-28 12:21:14
 * @LastEditors: 周波
 * @LastEditTime: 2021-02-28 12:21:14
 * @FilePath: /c++/stl.cc
 */
#include <iostream>
#include <stdint.h>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;

int32_t main(int32_t argc, char **args)
{
    std::vector<int32_t> val(10);
    std::iota(val.begin(), val.end(), 0);

    std::cout << std::accumulate(val.begin(), val.end(), 0) << std::endl;

    int32_t val_array[50];
    std::iota(val_array, val_array + 50, 0);

    std::cout << std::accumulate(val_array, val_array + 50, 0) << std::endl;

    string text{ "This is text" };
    std::iota(std::begin(text), std::end(text), 'K');
    std::cout << text << std::endl;  // Outputs: KLMNOPQRSTUV

    std::vector<string> words(8);
    std::iota(std::begin(words), std::end(words), "mysterious");
    std::copy(std::begin(words), std::end(words), std::ostream_iterator<string>{ std::cout, " " });
    std::cout << std::endl;  // mysterious ysterious sterious terious erious rious ious ous

    // std::distance
    // multiplies<int>()(3, 5)

    return 0;
}

// std::copy()
//std::back_inserter()