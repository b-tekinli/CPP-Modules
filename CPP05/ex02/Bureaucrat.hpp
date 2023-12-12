#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

using std::cout;
using std::endl;
using std::exception;
using std::ostream;
using std::string;

class AForm;

class Bureaucrat
{
private:
	const string	name;
	int				grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &oth);
	Bureaucrat(const string &name, int grade);
	~Bureaucrat();

	Bureaucrat		&operator=(const Bureaucrat &oth);
	const string	&getName() const;
	int				getGrade() const;
	void			incrementGrade();
	void			decrementGrade();
	void			signForm(AForm &form) const;
	void			executeForm(const AForm &form) const;

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

ostream		&operator<<(ostream &os, const Bureaucrat &bureaucrat);

#endif
