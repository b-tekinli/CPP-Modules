#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const string name, int grade) : name(name) 
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();

    this->grade = grade;
}

Bureaucrat::~Bureaucrat() { }

std::string Bureaucrat::getName() const 
{
    return name;
}

int Bureaucrat::getGrade() const 
{
    return grade;
}

void Bureaucrat::incrementGrade() 
{
    if (grade == 1)
        throw GradeTooHighException();

    grade--;
}

void Bureaucrat::decrementGrade() 
{
    if (grade == 150)
        throw GradeTooLowException();

    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Bureaucrat grade is too low";
}

ostream &operator<<(ostream &os, const Bureaucrat &oth) 
{
    os << oth.getName() << ", bureaucrat grade " << oth.getGrade();
    return os;
}
