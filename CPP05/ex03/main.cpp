#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    AForm *unknownForm = someRandomIntern.makeForm("unknown form", "Target");

    delete rrf;
    delete unknownForm;

    return 0;
}
