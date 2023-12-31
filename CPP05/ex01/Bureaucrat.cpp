#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHigh();
	else if (grade > 150)
		throw GradeTooLow();

	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &oth) : name(oth.name), grade(oth.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &oth)
{
	this->name = oth.name;
	this->grade = oth.grade;

	return (*this);
}

Bureaucrat::~Bureaucrat() {}

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
		throw Bureaucrat::GradeTooHigh();

	Bureaucrat temp = *this;
	++*this;

	return (temp);
}

Bureaucrat Bureaucrat::operator--(int)
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooLow();

	Bureaucrat temp = *this;
	--*this;

	return (temp);
}

std::string const Bureaucrat::getName() const { return (name); }

int Bureaucrat::getGrade() const { return (grade); }

void Bureaucrat::setGrade(int grade) { this->grade = grade; }

void Bureaucrat::incrementGrade()
{
	grade <= 1 ? throw GradeTooHigh() : grade--;
}

void Bureaucrat::decrementGrade()
{
	grade >= 150 ? throw GradeTooLow() : grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signs " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &oth)
{
	os << oth.getName() << ", bureaucrat grade " << oth.getGrade();
	return os;
}
