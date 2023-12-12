#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::endl;
using std::exception;
using std::ostream;
using std::string;

class Bureaucrat
{
private:
	string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(const string name, int grade);
	Bureaucrat(const Bureaucrat &oth);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &oth);
	Bureaucrat &operator++();
	Bureaucrat &operator--();
	Bureaucrat operator++(int);
	Bureaucrat operator--(int);

	string const getName() const;
	int getGrade() const;
	void setGrade(int grade);

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public exception
	{
		virtual const char *what() const throw();
	};
};

ostream &operator<<(ostream &os, const Bureaucrat &oth);

#endif
