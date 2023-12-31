#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &AFormName, const std::string &target) const
{
	std::string AFormNames[3] = {
		"shrubbery",
		"robotomy",
		"presidential"};

	int i = 0;
	while (i < 3 && AFormNames[i] != AFormName)
		i++;
	AForm *tmp = NULL;

	switch (i)
	{
	case 0:
		tmp = new ShrubberyCreationForm(target);
		break;
	case 1:
		tmp = new RobotomyRequestForm(target);
		break;
	case 2:
		tmp = new PresidentialPardonForm(target);
		break;
	default:
		throw Intern::InvalidAForm();
	}
	std::cout << "Intern creates " << AFormName << std::endl;

	return (tmp);
}
