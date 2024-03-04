#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	cout << "default constructor called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const string &tar) : AForm("Presidental Pardon Form", 25, 5), target(tar)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm("Presidental Pardon Form", 25, 5)
{
	*this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	*this = obj;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{

	if (!getIsSigned())
		throw AForm::GradeTooLowException();

	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	cout << target << " has been pardoned by Zaphod Beeblebrox." << endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
