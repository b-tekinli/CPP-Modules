#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
		throw AForm::GradeTooLow();

	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLow();

	std::cout << "Drilling noises..." << std::endl;

	srand(time(0));
	if (time(NULL) % 2 == 0)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed for " << target << "." << std::endl;
}
