#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            std::map<int, int> mappp;

            BitcoinExchange bit(av[1]);
            bit.locateCsvInMap();
            bit.start();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        } 
    }
    else
        std::cerr << "Error: could not open file." << std::endl;
    return (0);
}