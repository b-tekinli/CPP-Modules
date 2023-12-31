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
	~Form();

	class GradeTooHigh : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Form grade is too high!";
		}
	};

	class GradeTooLow : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Form grade is too low!";
		}
	};

	std::string getName() const;
	int getExecuteGrade() const;
	bool isSigned() const;
	int getSignGrade() const;
	void setSigned(bool signedStatus);
	void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
