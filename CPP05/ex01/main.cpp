#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("Daryl", 75);
		cout << bureaucrat << endl;

		Form form("Presidental Pardon Form", 75, 100);
		cout << form << endl;

		bureaucrat.signForm(form);
		cout << form << endl;

		bureaucrat.decrementGrade();
		cout << bureaucrat << endl;

		bureaucrat.signForm(form);
		cout << form << endl;
	}
	catch (const exception &e)
	{
		cout << "Exception: " << e.what() << endl;
	}

	return (0);
}
