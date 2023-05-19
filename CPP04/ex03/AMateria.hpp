#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string.h>
#include "ICharacter.hpp"

using std::cout;
using std::endl;
using std::string;

class AMateria
{
protected:
    string type;

public:
    AMateria(string const &type);
    AMateria(const AMateria &other);
    virtual ~AMateria();

    AMateria &operator=(const AMateria &other);

    string const &getType() const;

    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif
