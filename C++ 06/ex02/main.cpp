#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::srand(std::time(0));

        Base *randomClass = generate();

        identify(randomClass);

        delete randomClass;
    }
    return (0);
}