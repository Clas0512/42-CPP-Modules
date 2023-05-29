#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < ac; i++)
        {
            for (int j = 0; av[i][j]; j++)
            {
                if (std::islower(av[i][j]))
                    std::cout << (char)std::toupper(av[i][j]);
                else
                    std::cout << av[i][j];
            }
        }
    }
    std::cout << std::endl;
    return (0);
}