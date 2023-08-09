#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <random>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string const _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        virtual ~RobotomyRequestForm();
        std::string getTarget() const;
        void    execute(Bureaucrat const & executor) const ;
};

#endif