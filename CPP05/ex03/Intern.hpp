#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
    Intern();
    ~Intern();

    AForm *makeForm(const string &formName, const string &formTarget) const;

    class InvalidAFormException : public exception
    {
    public:
        const char *what() const throw()
        {
            return "Invalid AForm type";
        }
    };
};

#endif
