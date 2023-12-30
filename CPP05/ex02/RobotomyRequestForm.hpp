#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
	const string target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const string &target);
	~RobotomyRequestForm();

	void execute(const Bureaucrat &executor) const;
};

#endif
