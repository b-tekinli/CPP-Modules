#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat("Daryl", 12);
	
	try
	{
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;

		Bureaucrat invalidBureaucrat("Rick", 0);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
