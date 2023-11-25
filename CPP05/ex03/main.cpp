#include "Intern.hpp"

int main()
{
    try
    {       
        Intern someRandomIntern;
        AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        AForm *unknownForm = someRandomIntern.makeForm("unknown form", "Target");

        delete rrf;
        delete unknownForm;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    

    return 0;
}
