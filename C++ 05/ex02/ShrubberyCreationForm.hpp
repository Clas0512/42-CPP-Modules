#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <ctime>
# include <cstdlib>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string const _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
        virtual ~ShrubberyCreationForm();
        std::string getTarget() const;
        void    execute(Bureaucrat const & executor) const ;
};

#endif