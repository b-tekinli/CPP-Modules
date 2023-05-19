#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(Cure const &oth);
    virtual ~Cure();

    Cure &operator=(Cure const &oth);

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif
