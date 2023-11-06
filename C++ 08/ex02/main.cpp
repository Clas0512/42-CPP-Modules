#include "MutantStack.hpp"

void test()
{
    std::cout << "------- TEST -------" << std::endl << std::endl << std::endl;

    MutantStack<int> kopek;

    for (size_t i = 0; i < 12; i++)
    {
        kopek.push(i);
    }
    kopek.push(124);
    kopek.push(345);

    std::cout << "size before something add: " << kopek.size() << std::endl;
    std::cout << "current top element: " << kopek.top() << std::endl;

    std::cout << "adding an element.." << std::endl;
    kopek.push(4242);
    std::cout << "size after something add: " << kopek.size() << std::endl;
    std::cout << "current top element: " << kopek.top() << std::endl;

    kopek.pop();
    kopek.pop();

    std::cout << "size after something delete: " << kopek.size() << std::endl;
    std::cout << "current top element: " << kopek.top() << std::endl;

    std::cout << "Printing all elements of stack with ITERATORS.." << std::endl;

    MutantStack<int>::iterator itr = kopek.begin();
    MutantStack<int>::iterator rti = kopek.end();


    for (; itr != rti; itr++)
    {
        std::cout << *itr << std::endl;
    }
}

void main_test()
{
    std::cout << "------- MAIN_TEST -------" << std::endl << std::endl << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

int main()
{
    test();
    main_test();
    return (0);
}