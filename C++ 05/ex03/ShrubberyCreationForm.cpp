#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(0, 0, "Shrubbery"), _target("no target")
{
	std::cout << "Shrubbery Default Constructor Call" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(145, 137, "Shrubbery"), _target(target)
{
	std::cout << "Shrubbery Target Constructor Call" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : _target("copy" + copy.getTarget())
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Default Destructor Call" << std::endl;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	(void) other;
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	int level;

	checkSignAndExec(executor);
	std::ofstream writeFile(getTarget() + "_shrubbery.txt");
	level = getTarget().length();
	if (level < 3)
		level = 3;
    for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level - i - 1; ++j){
        	writeFile << " ";
    	}
        for (int k = 0; k < 2 * i + 1; ++k){
        	writeFile << "*";
    	}
        writeFile << std::endl;
	}
    for (int z = 0; z < level - 1; ++z){
        writeFile << " ";
    }
    writeFile << "*";
    writeFile << std::endl;
}