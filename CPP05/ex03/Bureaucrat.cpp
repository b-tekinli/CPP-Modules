#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150) {  }

Bureaucrat::Bureaucrat(const string &name, int grade)
	: name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &oth) : name(oth.name), grade(oth.grade) { }

Bureaucrat::~Bureaucrat() {  }

const string &Bureaucrat::getName() const { return (name); }

int Bureaucrat::getGrade() const { return (grade); }

void Bureaucrat::incrementGrade()
{
	grade <= 1 ? throw GradeTooHighException() : grade--;
}

void Bureaucrat::decrementGrade()
{
	grade >= 150 ? throw GradeTooLowException() : grade++;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &oth)
{
	this->grade = oth.grade;

	return (*this);
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		cout << *this << " signs " << form << endl;
	}
	catch (const exception &e)
	{
		cout << *this << " cannot sign " << form << " because " << e.what() << endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		cout << *this << " executed " << form << endl;
	}
	catch (const exception &e)
	{
		cout << *this << " cannot execute " << form << " because " << e.what() << endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Bureaucrat grade is too high!"; }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Bureaucrat grade is too low!"; }

ostream &operator<<(ostream &os, const Bureaucrat &bureaucrat)
{
	os << "Bureaucrat: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade();
	return (os);
}
