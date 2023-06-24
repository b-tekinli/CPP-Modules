#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const string &target)
    : AForm("Shrubbery Creation Form", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw AForm::GradeTooLowException();

    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException();

    ofstream outputFile(target + " shrubbery");

    if (outputFile)
    {
        outputFile << "ASCII trees go here..." << endl;
        outputFile.close();
        cout << "Shrubbery created for " << target << "." << endl;
    }
    else
    {
        throw runtime_error("Failed to create shrubbery file for " + target + ".");
    }
}