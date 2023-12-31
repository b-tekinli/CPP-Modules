#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &oth) : name(oth.name), grade(oth.grade) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHigh();
	else if (grade > 150)
		throw GradeTooLow();

	this->grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &oth)
{
	this->name = oth.name;
	this->grade = oth.grade;
	return (*this);
}

Bureaucrat &Bureaucrat::operator++()
{
	this->grade++;
	return (*this);
}

Bureaucrat &Bureaucrat::operator--()
{
	this->grade--;
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int)
{
	if (grade >= 150)
		throw GradeTooLow();
	Bureaucrat temp = *this;
	++*this;

	return (temp);
}

Bureaucrat Bureaucrat::operator--(int)
{
	if (grade <= 1)
		throw GradeTooHigh();
	Bureaucrat temp = *this;
	--*this;
	return (temp);
}

std::string const Bureaucrat::getName() const { return (name); }

int Bureaucrat::getGrade() const { return (grade); }

void Bureaucrat::setGrade(int grade) { this->grade = grade; }

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHigh();
	else
		grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw GradeTooLow();
	else
		grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &oth)
{
	os << oth.getName() << ", bureaucrat grade " << oth.getGrade();
	return (os);
}
