#include <iostream>

template<typename T>
void swap(T a, T b)
{
    T tmp;
    std::cout << "before a: " << a << std::endl;
    std::cout << "before b: " << b << std::endl;

    tmp = a;
    a = b;
    b = tmp;

    std::cout << "after a: " << a << std::endl;
    std::cout << "after b: " << b << std::endl;
}

template<typename Z>
Z min(Z a, Z b)
{
    if (a == b)
        return (b);
    else
        return ((a > b) ? b : a);
}

template<typename K>
K max(K a, K b)
{
    if (a == b)
        return (b);
    else
        return ((a < b) ? b : a);
}