#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150)
{
    return;
}

Bureaucrat::Bureaucrat(const string name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();

    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &oth) : name(oth.name), grade(oth.grade) { }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &oth)
{
    this->name = oth.name;
    this->grade = oth.grade;

    return (*this);
}

Bureaucrat::~Bureaucrat() { }

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

Bureaucrat Bureaucrat::operator++(int) {
    if (grade >= 150)
        throw Bureaucrat::GradeTooHighException();
    
    Bureaucrat temp = *this;
    ++*this;

    return (temp);
}

Bureaucrat Bureaucrat::operator--(int) {
    if (grade <= 1)
        throw Bureaucrat::GradeTooLowException();
    
    Bureaucrat temp = *this;
    --*this;

    return (temp);
}

string const Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::setGrade(int grade)
{
    this->grade = grade;

    return;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    else
        grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    else
        grade++;
}

ostream &operator<<(ostream &os, const Bureaucrat &oth)
{
    os << oth.getName() << ", bureaucrat grade " << oth.getGrade();
    
    return (os);
}
