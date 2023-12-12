#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const string &target)
	: AForm("Robotomy Request Form", 72, 45), target(target) {  }

RobotomyRequestForm::~RobotomyRequestForm() {  }

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
		throw AForm::GradeTooLowException();

	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();

	cout << "Drilling noises..." << endl;
	if (time(NULL) % 2 == 0)
		cout << target << " has been robotomized successfully." << endl;
	else
		cout << "Robotomy failed for " << target << "." << endl;
}
