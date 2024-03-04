#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), signGrade(1), executeGrade(1) {}

Form::Form(const std::string &name, const int signGrade, const int executeGrade)
	: name(name), signGrade(signGrade), executeGrade(executeGrade)
{
	signedStatus = false;

	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &oth) : name(oth.getName()), signGrade(oth.getSignGrade()), executeGrade(oth.getExecuteGrade())
{
	signedStatus = oth.isSigned();
	*this = oth;
}

Form &Form::operator=(const Form &oth)
{
	signedStatus = oth.isSigned();
	return *this;
}

Form::~Form() {}

std::string Form::getName() const { return name; }

bool Form::isSigned() const { return signedStatus; }

int Form::getExecuteGrade() const { return executeGrade; }

int Form::getSignGrade() const { return signGrade; }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (!signedStatus && bureaucrat.getGrade() <= this->getSignGrade())
		bureaucrat.getGrade() <= signGrade ? signedStatus = true : throw GradeTooLowException();
	else
		throw GradeTooHighException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high !\n";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low !\n";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No") << ", Sign Grade: " << form.getSignGrade()
	   << ", Execute Grade: " << form.getExecuteGrade();
	return os;
}
