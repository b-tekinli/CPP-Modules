#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation Form", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
		throw AForm::GradeTooLow();

	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLow();

	std::string str = target + "_shrubbery";
	std::ofstream outputFile(str.c_str());

	if (outputFile)
	{
		outputFile << "                    \\\n"
					  "          |         |\n"
					  "          |       \\ /\\ \n"
					  "   _ .     \\   „;=`y   .   |\n"
					  " .⁻⁻> \\«  ` |  `: /”» '   /\\ \n"
					  ". ,/ `\\;`.  `=„\\`/; „='  ”.='    |\n"
					  " '   , =\\;` /, =”;„  ==./--=.”» /\n"
					  "    '     \\\\`v  8/,”-./ ``  ,-`/--'\n"
					  "           \\\\\\|//  ` v__,=”   \\ \n"
					  "            \\\\y¡' _,/,<='      \n"
					  "             \\8|y',-'  ``\\ \n"
					  "             |{ o/\\\n"
					  "             |) |\n"
					  "             |; |\n"
					  "             |; |\n"
					  "            „{) o\\ \n"
				   << std::endl;
		outputFile.close();
		std::cout << "Shrubbery created for " << target << "." << std::endl;
	}
	else
	{
		throw std::runtime_error("Failed to create shrubbery file for " + target + ".");
	}
}
