#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(Ice const &oth);
    virtual ~Ice();

    Ice &operator=(Ice const &oth);

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};

#endif
