#include "AForm.hpp"

AForm::AForm() : name("default"), gradeToSign(150), gradeToExecute(150)
{
    cout << "default constructor called" << endl;
    isSigned = false;
}

AForm::AForm(const string fName, const int grToSign, const int grToExec) : name(fName), gradeToSign(grToSign), gradeToExecute(grToExec)
{
    isSigned = false;
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooHighException();
    else if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &obj) : name(obj.getName()), gradeToSign(obj.getGradeToSign()), gradeToExecute(obj.getGradeToExecute())
{
    isSigned = obj.getIsSigned();
    *this = obj;
}

AForm &AForm::operator=(const AForm &obj)
{
    isSigned = obj.getIsSigned();
    return *this;
}

AForm::~AForm()
{
}

string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getGradeToSign())
    {
        isSigned = true;
        cout << bureaucrat.getName() << " signed " << name << endl;
    }
    else
    {
        cout << bureaucrat.getName() << " couldn't sign " << name << " because of grade" << endl;
        throw AForm::GradeTooLowException();
    }
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high !!\n";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low !!\n";
}

std::ostream &operator<<(std::ostream &out, AForm &Aform)
{
    out << Aform.getName() + " Aform is " << (Aform.getIsSigned() ? "signed," : "not signed,");
    out << " requires grade " << Aform.getGradeToSign() << " to sign and grade ";
    out << Aform.getGradeToExecute() << " to execute";
    return (out);
}