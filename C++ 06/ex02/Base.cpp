#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}

Base* generate()
{
    int randomChoice = rand() % 3;

    switch (randomChoice)
    {
    case 0:
        return (new A());
    case 1:
        return (new B());
    case 2:
        return (new C());
    default:
        return (nullptr);
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "It's * A *" << std::endl;
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "It's * B *" << std::endl;
    else if (dynamic_cast<C*>(p) != nullptr)
        std::cout << "It's * C *" << std::endl;
    else
        std::cout << "Not found!" << std::endl;
}

void identify(Base& p)
{
    identify(&p);
}