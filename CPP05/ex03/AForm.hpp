#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool sign;
	const int signGrade;
	const int executeGrade;

public:
	AForm(const std::string &name, int signGrade, int executeGrade);
	virtual ~AForm();

	const std::string &getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;

	class GradeTooHigh : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLow : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
