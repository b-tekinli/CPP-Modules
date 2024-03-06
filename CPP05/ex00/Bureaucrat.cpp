#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called.\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowExceptionException();

	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &oth) : name(oth.getName()), grade(oth.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &oth)
{
	this->grade = oth.getGrade();

	return (*this);
}

std::string Bureaucrat::getName() const { return (name); }

int Bureaucrat::getGrade() const { return (grade); }

void Bureaucrat::incrementGrade()
{
	if (grade < 1)
		throw GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade > 150)
		throw GradeTooLowExceptionException();
	else
		grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high!\n";
}

const char *Bureaucrat::GradeTooLowExceptionException::what() const throw()
{
	return "Bureaucrat grade is too low!\n";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &oth)
{
	os << oth.getName() << ", bureaucrat grade " << oth.getGrade();
	return (os);
}
