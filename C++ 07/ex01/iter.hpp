#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename I, typename F, typename Z>
void iter(I *iArray, size_t length, F function(Z &element)){
    for (size_t i = 0; i < length; i++)
        function(iArray[i]);
}

#endif