#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat& operator=(const Bureaucrat& other);
        virtual ~Bureaucrat(); // To use a virtual destructor in a class which included virtual functions or methods are better in terms of memory management because of may be included some exception.
        std::string getName(void) const;
        int getGrade(void) const;
        void    incrementGrade();
        void    decrementGrade();
        class    GradeTooHighException : public std::exception{
                public:
                    virtual const char* what() const throw() // throw() keyword used to terminate the program in a defined way.
                    {
                        return ("Too High Grade!");
                    };
        };
        class    GradeTooLowException : public std::exception{
                public:
                    virtual const char* what() const throw()
                    {
                        return ("Too High Grade!");
                    };
        };
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat &other);

#endif