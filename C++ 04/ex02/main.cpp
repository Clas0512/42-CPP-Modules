#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


int main()
{
    const Animal* j = new Dog();
    std::cout << std::endl;
    const Animal* i = new Cat();
    std::cout << std::endl;

    delete j;
    delete i;

    return (0);
}