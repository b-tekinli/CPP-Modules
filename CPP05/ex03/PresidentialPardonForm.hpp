#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const string	target;
public:
	PresidentialPardonForm(const string &target);
	~PresidentialPardonForm();

	void	execute(const Bureaucrat &executor) const;
};

#endif
