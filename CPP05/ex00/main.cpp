#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat("Daryl", 3);
	
	try
	{
		cout << bureaucrat << endl;

		bureaucrat.incrementGrade();
		cout << bureaucrat << endl;

		bureaucrat.decrementGrade();
		cout << bureaucrat << endl;

		Bureaucrat invalidBureaucrat("Rick", 0);
	}
	catch (const exception &e)
	{
		cout << "Exception caught: " << e.what() << endl;
	}
	return (0);
}
