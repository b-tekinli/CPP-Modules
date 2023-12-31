#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Pardon Form", 25, 5)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon Form", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
		throw AForm::GradeTooLow();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooHigh();

	std::cout << target << "has been pardoned by Zaphod Beeblebrox.\n";
}
