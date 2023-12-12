#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
using std::ofstream;
using std::runtime_error;


class ShrubberyCreationForm : public AForm
{
private:
	const string target;

public:
	ShrubberyCreationForm(const string &target);
	~ShrubberyCreationForm();

	void	execute(const Bureaucrat &executor) const;
};

#endif
