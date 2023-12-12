#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const string &target)
	: AForm("Presidential Pardon Form", 25, 5), target(target) {  }

PresidentialPardonForm::~PresidentialPardonForm() {  }

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!isSigned())
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooHighException();

	cout << target << "has been pardoned by Zaphod Beeblebrox.\n" << endl;
}
