#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
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