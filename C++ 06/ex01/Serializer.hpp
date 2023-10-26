#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

class Serializer{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
        Serializer();
		Serializer(Serializer const &copy);
		Serializer &operator=(Serializer const &other);
		~Serializer();
};

#endif