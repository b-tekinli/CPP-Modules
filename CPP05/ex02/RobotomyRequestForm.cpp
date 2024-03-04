#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    cout << "default constructor called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const string &tar) : AForm("Robotomy Request Form", 72, 45), target(tar)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm("Robotomy Request Form", 72, 45)
{
    *this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    *this = obj;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw AForm::GradeTooLowException();

    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    cout << "Some drilling noises...\n";

    srand(time(0));

    if (rand() % 2 == 0)
        cout << target << " has been robotomized successfully.\n";
    else
        cout << "Robotomy on " << target << " has failed.\n";
}
