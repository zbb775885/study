#include <iostream>
#include <stdint.h>

class Test
{
public:
    Test(int32_t a, int32_t b)
    {
        a_ = a;
        b_ = b;
        c_ = 10;
        self = this;
    }
    ~Test()
    {
    }

public:
    friend std::ostream &operator<<(std::ostream &out, const Test &test);

public:
    Test *operator->(void)
    {
        return this->self;
    }

public:
    //一元重载
    Test &operator++(void) //前缀自增
    {
        ++this->a_;
        return *this;
    }

    Test operator++(int32_t) //后缀自增
    {
        Test test(*this);
        this->a_++;

        return test;
    }

    Test operator-(void) ///负数
    {
        Test test(*this);
        test.a_ = -test.a_;

        return test;
    }

    Test operator!(void) ///负数
    {
        Test test(*this);
        test.a_ = !test.a_;

        return test;
    }

public:
    //二元重载
    Test operator+(Test &t1)
    {
        Test test(*this);
        test.a_ += t1.a_;

        return test;
    }

    Test operator-(Test &t1)
    {
        Test test(*this);
        test.a_ -= t1.a_;

        return test;
    }

    Test operator*(Test &t1)
    {
        Test test(*this);
        test.a_ = test.a_ * t1.a_;

        return test;
    }

    Test operator/(Test &t1)
    {
        Test test(*this);
        test.a_ = test.a_ / t1.a_;

        return test;
    }

    Test &operator=(Test &t1)
    {
        this->a_ = t1.a_;
        this->b_ = t1.b_;

        return *this;
    }

    int32_t c_;

private:
    int32_t a_;
    int32_t b_;
    Test *self;
};

std::ostream &operator<<(std::ostream &out, const Test &test)
{
    out << "a is " << test.a_ << " b is " << test.b_ << std::endl;
    return out;
}

int32_t main(int32_t argc, char **args)
{
    Test t1(1, 2);
    Test t2(3, 4);

    std::cout << t1 + t2 << std::endl;
    ///特殊符号
    std::cout << t1->c_ << std::endl;

    ///一元操作符重载
    std::cout << t1++ << std::endl;
    std::cout << ++t1 << std::endl;
    std::cout << -t1 << std::endl;
    std::cout << !t1 << std::endl;

    ///二元操作符重载
    std::cout << t1 + t2 << std::endl;
    std::cout << t1 * t2 << std::endl;
    std::cout << t1 / t2 << std::endl;
    t1 = t2;
    std::cout << t1 << std::endl;

    return 0;
}
