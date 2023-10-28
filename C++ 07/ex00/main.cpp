#include "Templates.cpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac == 1)
    {
        int i;
        int j;
        int minimum;
        int maximum;

        i = 1;
        j = 3;

        swap<int>(i, j);
        minimum = min<int>(i, j);

        std::cout << "minimum: " << minimum << std::endl;

        maximum = max<int>(i, j);

        std::cout << "maximum: " << maximum << std::endl;
    }
    return (0);
}