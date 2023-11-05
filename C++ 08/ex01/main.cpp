#include "Span.hpp"

int main()
{
    try
    {
        Span aSpan = Span(9);

        int numbersToAdd[9] = {1, 42, 2, 20, 23, 12, 43, 5, 6};
        aSpan.addNumber(numbersToAdd, 9);

        std::cout << std::endl;

        std::cout << "Longest span: " << aSpan.longestSpan() << std::endl;
        std::cout << "Shortest span: " << aSpan.shortestSpan() << std::endl;
    }
    catch (Span::BoundOfArray& exc)
    {
        std::cout << exc.what() << std::endl;
    }

    return (0);
}