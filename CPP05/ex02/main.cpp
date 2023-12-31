#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("Darly", 40);

		PresidentialPardonForm pardonForm("Maggie");
		RobotomyRequestForm robotomyForm("Jesus");
		ShrubberyCreationForm shrubberyForm("home");

		bureaucrat.signForm(shrubberyForm);
		bureaucrat.signForm(robotomyForm);
		bureaucrat.signForm(pardonForm);

		bureaucrat.executeForm(shrubberyForm);
		bureaucrat.executeForm(robotomyForm);
		bureaucrat.executeForm(pardonForm);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception occurred: " << e.what() << std::endl;
	}

	return (0);
}
