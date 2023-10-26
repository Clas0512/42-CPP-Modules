#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

int main(void)
{
    std::srand(std::time(0));

    Base *randomClass = generate();

    identify(randomClass);

    delete randomClass;

    return (0);
}