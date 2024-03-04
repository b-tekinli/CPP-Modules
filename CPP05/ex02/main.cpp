#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Darly", 3);
        ShrubberyCreationForm shrubberyForm("home");

        bureaucrat.signForm(shrubberyForm);
        bureaucrat.executeForm(shrubberyForm);

        RobotomyRequestForm robotomyForm("Jesus");
        bureaucrat.signForm(robotomyForm);
        bureaucrat.executeForm(robotomyForm);

        PresidentialPardonForm pardonForm("Maggie");
        bureaucrat.signForm(pardonForm);
        bureaucrat.executeForm(pardonForm);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
