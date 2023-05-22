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

    void signForm(class Form &form);

    class GradeTooHighException : public exception
    {
        const char *what() const throw() {
            return "Bureaucrat grade is too high!";
        }
    };

    class GradeTooLowException : public exception
    {
        const char *what() const throw() {
            return "Bureaucrat grade is too low!";
        }
    };
};

ostream &operator<<(ostream &os, const Bureaucrat &oth);

#endif
