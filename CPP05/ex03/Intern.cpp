#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &obj)
{
    *this = obj;
}
Intern &Intern::operator=(const Intern &obj)
{
    *this = obj;
    return *this;
}

Intern::~Intern()
{
}

const char *Intern::InvalidArgument::what() const throw()
{
    return "Invalid argument !\n";
}

AForm *Intern::makeForm(const string &formName, const string &formTarget)
{
    string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"};

    int i = 0;
    while (i < 3)
    {
        if (names[i] == formName)
            break;
        i++;
    }

    AForm *tmp = NULL;

    switch (i)
    {
    case 0:
        tmp = new ShrubberyCreationForm(formTarget);
        break;
    case 1:
        tmp = new RobotomyRequestForm(formTarget);
        break;
    case 2:
        tmp = new PresidentialPardonForm(formTarget);
        break;
    default:
        throw Intern::InvalidArgument();
        break;
    }

    cout << "Intern creates " << tmp->getName() << endl;
    
    return tmp;
}