#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon Form", 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
		throw AForm::GradeTooLow();
	else if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooHigh();

	std::cout << target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
