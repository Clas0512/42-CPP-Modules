#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     Dog sibi;
//     Cat neco;

//     neco.makeSound();
//     sibi.makeSound();
//     return (0);
// }

int main()
{
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;

    // i->makeSound();
    // j->makeSound();
    // meta->makeSound();


    const WrongAnimal* meta = new WrongAnimal();
    // const WrongAnimal* j = new Dog();
    const WrongAnimal* i = new WrongCat();

    // std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    // j->makeSound();
    meta->makeSound();


    return (0);
}