#include <iostream>
#include <stdint.h>

class Test
{
public:
    Test(int32_t a, int32_t b)
    {
        a_ = a;
        b_ = b;
    }
    ~Test()
    {
    }

public:
    //一元重载
    int32_t operator++() //前缀自增
    {
        return ++this->a_;
    }

    int32_t operator++(int32_t) //后缀自增
    {
        return this->a_++;
    }

    //二元重载
    int32_t operator+(Test &t1)
    {
        return this->a_ + t1.a_;
    }

    int32_t operator-(Test &t1)
    {
        return this->a_ - t1.a_;
    }

private:
    int32_t a_;
    int32_t b_;
};

int32_t main(int32_t argc, char **args)
{
    Test t1(1, 2);
    Test t2(3, 4);

    std::cout << t1 + t2 << std::endl;

    std::cout << t1++ << std::endl;
    std::cout << ++t1 << std::endl;

    std::cout << t1 + t2 << std::endl;

    return 0;
}
