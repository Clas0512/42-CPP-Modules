#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>


class noInArray : public std::exception
{
    public:
        const char* what() const throw(){
            return ("Not Found!");
        }
};

template<typename T>
typename T::iterator easyfind(T& first, int second)
{
    typename T::iterator itr;

    itr = std::find(first.begin(), first.end(), second);

    if (itr == first.end())
        throw noInArray();
    else
        return (itr);
};

#endif