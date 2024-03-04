#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    cout << "Shrubbery default constructor" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const string &tar) : AForm("Shrubbery Creation Form", 145, 137), target(tar)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm("Shrubbery Creation Form", 145, 137)
{
    *this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    this->target = obj.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
    {
        throw AForm::GradeTooLowException();
    }

    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    string str = target + "_shrubbery";
    std::ofstream outputFile(str.c_str());

    if (outputFile.is_open())
    {
        outputFile << "          &&& &&  & &&\n";
        outputFile << "      && &//&||& ()|/ @, &&\n";
        outputFile << "      &//(/&/&||/& /_/)_&/_&\n";
        outputFile << "   &() &//&|()|/&/// '%' & ()\n";
        outputFile << "  &_/_&&_/ |& |&&/&__%_/_& &&\n";
        outputFile << "&&   && & &| &| /& & % ()& /&&\n";
        outputFile << " ()&_---()&/&/|&&-&&--%---()~\n";
        outputFile << "     &&     /|||\n";
        outputFile << "             |||\n";
        outputFile << "             |||\n";
        outputFile << "             |||\n";
        outputFile << "       , -=-~  .-^- _\n";
        outputFile.close();
        cout << "Shrubbery created for " << target << "." << endl;
    }
    else
        cout << "Errorrr" << endl;
}