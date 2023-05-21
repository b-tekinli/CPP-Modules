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
    const string name;
    int grade;

public:
    Bureaucrat(const string name, int grade);
    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &oth);
    Bureaucrat &operator++();
    Bureaucrat &operator--();
    Bureaucrat operator++(int);
    Bureaucrat operator--(int);

    string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public exception
    {
        const char *what() const throw();
    };

    class GradeTooLowException : public exception
    {
        const char *what() const throw();
    };
};

ostream &operator<<(ostream &os, const Bureaucrat &oth);

#endif
