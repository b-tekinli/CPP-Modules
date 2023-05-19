#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &oth) : AMateria(oth) {}

Cure::~Cure() {}

Cure &Cure::operator=(Cure const &oth)
{
    if (this != &oth)
    {
        AMateria::operator=(oth);
    }
    return (*this);
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    cout << "* heals " << target.getName() << "'s wounds *" << endl;

    AMateria::use(target);
}
