#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>

class Span {
    private:
        const unsigned int maxSize;
        std::vector<int> numbers;
    public:
        Span(unsigned int N);
        void    addNumber(int number);
        void    addNumber(int *number, int len);
        class BoundOfArray : public std::exception {
            public:
                const char* what() const throw() {
                    return ("Numbers array is full!");
                };
        };
        class notANumberForCmp : public std::exception {
            public:
                const char* what() const throw() {
                    return ("Not found a number for compare!");
                };
        };
        void    printNumbers();
        int     shortestSpan();
        int     longestSpan();
};

#endif