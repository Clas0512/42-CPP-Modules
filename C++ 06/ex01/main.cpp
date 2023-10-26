#include "Serializer.hpp"

int main(int ac, char **av)
{
    if (ac == 1)
    {
        Data *lidarData;
        uintptr_t handlePointer;
        void *lastPointer;

        lidarData = new Data;
        lidarData->Content = "4.3462, 3.4352, 5.1742";

        std::cout << "Original Data Pointer\t\t\t\t\t\t -> " << lidarData << std::endl;

        handlePointer = Serializer::serialize(lidarData);
        std::cout << "Data Pointer after process of serialize with UINTPTR_T type\t -> " << handlePointer << std::endl;

        lastPointer = Serializer::deserialize(handlePointer);
        std::cout << "Data Pointer after process of deserialize\t\t\t -> " << lastPointer << std::endl << std::endl;

        std::cout << "\t\t\tCOMPARE" << std::endl;
        std::cout << "Original\t -> " << lidarData << std::endl;
        std::cout << "Current\t\t -> " << lastPointer << std::endl;

        delete lidarData;
    }
    return (0);
}