#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("John Doe", 50);

        ShrubberyCreationForm shrubberyForm("home");
        RobotomyRequestForm robotomyForm("John");
        PresidentialPardonForm pardonForm("Jane");

        bureaucrat.signForm(shrubberyForm);
        bureaucrat.signForm(robotomyForm);
        bureaucrat.signForm(pardonForm);

        bureaucrat.executeForm(shrubberyForm);
        bureaucrat.executeForm(robotomyForm);
        bureaucrat.executeForm(pardonForm);
    }
    catch (const exception &e)
    {
        cout << "Exception occurred: " << e.what() << endl;
    }

    return (0);
}
