#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# define PURPLE "\x1B[35m"
# define END "\033[0m"

class RobotomyRequestForm : public AForm
{
    private:
        std::string const _target;
        std::string zort;
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