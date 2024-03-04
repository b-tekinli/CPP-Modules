#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

private:
    string target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const string &tar);
    ShrubberyCreationForm(const ShrubberyCreationForm &obj);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;
};