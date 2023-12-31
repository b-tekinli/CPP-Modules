#include "AForm.hpp"

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: name(name), sign(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHigh();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLow();
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return (name); }

bool AForm::isSigned() const { return (sign); }

int AForm::getSignGrade() const { return (signGrade); }

int AForm::getExecuteGrade() const { return (executeGrade); }

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= signGrade)
		sign = true;
	else
		throw GradeTooLow();
}

void AForm::execute(Bureaucrat const &execute) const {
	if(!this->isSigned()) {
		throw AForm::FormNotSigned();
	}
	if(execute.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLow();
	return;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form: " << form.getName() << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade() << ", Signed: " << (form.isSigned() ? "Yes" : "No");
	return (os);
}
