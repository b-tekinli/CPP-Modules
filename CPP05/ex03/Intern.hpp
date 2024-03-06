#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{

public:
    Intern();
    Intern(const Intern &obj);
    Intern &operator=(const Intern &obj);
    ~Intern();

    AForm *makeForm(const string &formName, const string &formTarget);
    
    class InvalidArgument : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};