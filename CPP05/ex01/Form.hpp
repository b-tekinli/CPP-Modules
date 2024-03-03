#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool signedStatus;
	const int signGrade;
	const int executeGrade;

public:
	Form();
	Form(const std::string &name, int signGrade, int executeGrade);
	Form(const Form &oth);
	Form &operator=(const Form &oth);
	~Form();

	std::string getName() const;
	bool isSigned() const;
	int getExecuteGrade() const;
	int getSignGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw() {}
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw() {}
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
