#include "Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		AForm *rrf = someRandomIntern.makeForm("shrubbery", "Bender");
		AForm *unknownForm = someRandomIntern.makeForm("unknown", "Target");
		Bureaucrat man("men", 1);

		man.signForm(*rrf);
		rrf->execute(man);
		
		delete rrf;
		delete unknownForm;
	}
	catch (const exception &e)
	{
		cerr << e.what() << '\n';
	}

	return 0;
}
