#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm(const string &target);
    ~ShrubberyCreationForm();

    void execute(const Bureaucrat &executor) const;
};

#endif
