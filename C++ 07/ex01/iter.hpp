#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename I, typename F>
void iter(I *iArray, size_t length, F function(I *element)){
    for (size_t i = 0; i < length; i++)
        function(&iArray[i]);
};

#endif