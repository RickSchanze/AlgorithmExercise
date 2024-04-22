#include <iostream>

class A {
public:
    ~A()
    {
        std::cout << "delete A" << std::endl;
    }
};

int main()
{
    std::cout << "hello world!" << std::endl;
    void* p = new A();
    delete p;
}