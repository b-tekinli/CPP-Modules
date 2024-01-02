#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &oth);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &oth);
	Bureaucrat &operator++();
	Bureaucrat &operator--();
	Bureaucrat operator++(int);
	Bureaucrat operator--(int);

	std::string const getName() const;
	int getGrade() const;
	void setGrade(int grade);

	void incrementGrade();
	void decrementGrade();

	class GradeTooHigh : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Bureaucrat grade is too high!";
		}
	};
	
	class GradeTooLow : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Bureaucrat grade is too low!";
		}
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &oth);

#endif
