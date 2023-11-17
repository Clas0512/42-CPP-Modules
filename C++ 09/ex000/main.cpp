#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            std::map<int, int> mappp;
            // std::map<int, int>::iterator its = mappp.begin();
        
            mappp.insert(std::make_pair(2, 3));
            mappp.insert(std::make_pair(3, 4));

            
            std::cout << mappp[2] << std::endl;
            std::cout << mappp[3] << std::endl;

            exit(0);

            BitcoinExchange bit(av[1]);
            std::map<int *, float> tmpMap = bit.getMap();
            std::map<int *, float>::iterator it = tmpMap.begin();
            bit.locateCsvInMap();

            std::cout << "asd" << std::endl;
            for (; it != tmpMap.end(); ++it) {
                std::cout << it->first << ", " << std::endl;
                }
            std::cout << "asd" << std::endl;
            // calculateBitcoins();
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