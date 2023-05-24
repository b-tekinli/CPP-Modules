#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const string name;
    bool isSigned;
    const int signGrade;
    const int executeGrade;

public:
    AForm(const string &name, int signGrade, int executeGrade);
    virtual ~AForm();

    const string &getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);

    virtual void execute(const Bureaucrat &executor) const = 0;

    class GradeTooHighException : public exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public exception
    {
    public:
        const char *what() const throw();
    };
};

ostream &operator<<(ostream &os, const AForm &form);

#endif
