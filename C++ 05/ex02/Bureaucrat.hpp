#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class Form;

class Bureaucrat{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat& operator=(const Bureaucrat& other);
        virtual ~Bureaucrat();
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
                        return ("Too Low Grade!");
                    };
        };
        void    signForm(AForm &signForm) const;
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat &other);

#endif