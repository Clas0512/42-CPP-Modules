#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Default Constructor Call" << std::endl;	
}

Serializer::Serializer(const Serializer &copy)
{
	std::cout << "Copy Constructor Call" << std::endl;
    *this = copy;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer()
{
	std::cout << "Default Destructor Call" << std::endl;	
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}