#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("Daryl", 75);
		std::cout << bureaucrat << std::endl;

		Form form("Presidental Pardon Form", 75, 100);
		std::cout << form << std::endl;

		bureaucrat.signForm(form);
		std::cout << form << std::endl;

		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
