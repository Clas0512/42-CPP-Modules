#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

    if (ac == 2)
    {
        BitcoinExchange bit;
        try
        {
            openFiles();
            calculateBitcoins();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    else
        std::cerr << "Error :   invalid argument." << std::endl;
    return (0);
}