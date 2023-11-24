#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac >= 3)
    {
        try
        {
            std::cout << std::fixed;
            PmergeMe main(av, ac);

            main.createContainers();
            std::cout << "Before:\t";
            main.printSeq();
            main.goSort();
            std::cout << "After:\t";
            main.printList();
            std::cout << "Time to process a range of " << main.getSeqLen() << " elements with std::vector :\t" << main.getVectorTime() << " us" << std::endl;
            std::cout << "Time to process a range of " << main.getSeqLen() << " elements with std::list :\t\t" << main.getListTime() << " us" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cout << "Error: please enter 2 or more argument." << std::endl;
    return (0);
}