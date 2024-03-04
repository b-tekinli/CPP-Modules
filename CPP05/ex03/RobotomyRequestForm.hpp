#pragma once
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
    string target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const string &tar);
    RobotomyRequestForm(const RobotomyRequestForm &obj);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const &executor) const;
};