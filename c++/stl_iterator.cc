#include <iostream>
#include <stdint.h>
#include <vector>
#include <numeric>
#include <map>

int32_t main(int32_t argc, char **args)
{
    std::string str("abc");
    std::cout << str << std::endl;
    std::swap(str[0], str[1]);
    std::string f = std::string("def");
    str.swap(f);
    std::cout << str << std::endl;

    std::map<int32_t, int32_t> map;
    map.begin();

    std::vector<int32_t> vector;
    vector.clear();
    auto vec = vector.begin();
    // std::swap();
    // std::cout << "sum is " << sum(1.5, 6.7) << std::endl;

    return 0;
}