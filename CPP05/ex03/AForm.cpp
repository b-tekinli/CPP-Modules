#include "AForm.hpp"

AForm::AForm(const string &name, int signGrade, int executeGrade)
	: name(name), sign(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {  }

const string &AForm::getName() const { return (name); }

bool AForm::isSigned() const { return (sign); }

int AForm::getSignGrade() const { return (signGrade); }

int AForm::getExecuteGrade() const { return (executeGrade); }

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= signGrade)
		sign = true;
	else
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() { return "Form grade is too high!"; }

const char *AForm::GradeTooLowException::what() const throw() { return "Form grade is too low!"; }

ostream &operator<<(ostream &os, const AForm &form)
{
	os << "Form: " << form.getName() << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade()
	   << ", Signed: " << (form.isSigned() ? "Yes" : "No");
	return (os);
}
