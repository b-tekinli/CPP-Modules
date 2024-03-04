#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("Darly", 1);

		Intern intern;

		AForm *form;
		form = intern.makeForm("robotomy request", "Bender");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);

		AForm *zombie = intern.makeForm("robot", "Bender");
		bureaucrat.signForm(*zombie);
		bureaucrat.executeForm(*zombie);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << endl;
	}
}
