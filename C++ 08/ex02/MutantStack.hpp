#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <vector>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>(){};
        MutantStack(const MutantStack& copy) : std::stack<T>(copy){};
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin()
        {
            return (std::stack<T>::c.begin());
        }
        iterator end()
        {
            return (std::stack<T>::c.end());
        }
};

#endif