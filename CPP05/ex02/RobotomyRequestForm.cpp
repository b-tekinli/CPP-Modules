#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 25, 5)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const string &target)
	: AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
		throw AForm::GradeTooLowException();

	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooHighException();

	cout << "Drilling noises..." << endl;

	if (rand() % 2 == 0)
		cout << target << " has been robotomized successfully." << endl;
	else
		cout << "Robotomy failed for " << target << "." << endl;
}
