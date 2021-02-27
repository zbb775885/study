#include <iostream>
#include <stdint.h>

int32_t abc(int32_t a, int32_t b, int32_t c)
{
    try
    {
        if (1 == a)
        {
            throw "ddddd";
        }
        else
        {
            throw std::bad_alloc();
        }
    }
    catch (std::exception &e)
    {
        //...抓取莫瑞诺的exception
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        //...表示所有的异常类型均捕获
        std::cerr << "err" << '\n';
        return 1;
    }

    return a * b * c;
}

int32_t bcd(int32_t a, int32_t b, int32_t c)
{
    throw "cccc";

    return a * b * c;
}

int32_t main(int32_t argc, char **args)
{
    abc(1, 0, 0);
    try
    {
        bcd(1, 0, 0);
    }
    catch (...)
    {
        std::cerr << "ccc" << '\n';
    }

    return 0;
}
