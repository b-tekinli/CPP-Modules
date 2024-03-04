#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	string target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const string &tar);
	PresidentialPardonForm(const PresidentialPardonForm &obj);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
	~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;
};

#endif
