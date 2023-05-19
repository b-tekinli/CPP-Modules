#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &oth) : AMateria(oth) {}

Ice::~Ice() {}

Ice &Ice::operator=(Ice const &oth)
{
    if (this != &oth)
    {
        AMateria::operator=(oth);
    }
    return *this;
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
    
    AMateria::use(target);
}
