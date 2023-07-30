#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

using namespace std;

int main()
{
    const Animal* j = new Dog();
    cout << endl;
    const Animal* i = new Cat();
    cout << endl;

    delete j;
    delete i;

    return (0);
}