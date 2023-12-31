#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &formTarget) const;

	class InvalidAForm : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Invalid AForm type";
		}
	};
};

#endif
