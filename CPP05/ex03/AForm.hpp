#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

using std::string;
using std::ostream;
using std::exception;

class AForm
{
private:
	const string	name;
	bool			sign;
	const int		signGrade;
	const int		executeGrade;

public:
	AForm(const string &name, int signGrade, int executeGrade);
	virtual	~AForm();

	const string	&getName() const;
	bool			isSigned() const;
	int				getSignGrade() const;
	int				getExecuteGrade() const;
	void			beSigned(const Bureaucrat &bureaucrat);
	virtual void	execute(const Bureaucrat &executor) const = 0;

	class GradeTooHighException : public exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public exception
	{
		public:
			virtual const char *what() const throw();
	};
};

ostream			&operator<<(ostream &os, const AForm &form);

#endif
