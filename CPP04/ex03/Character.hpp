#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    string name;
    AMateria *materia[4];

public:
    Character(const string &name);
    Character(Character const &other);
    virtual ~Character();

    Character &operator=(Character const &other);

    string const &getName() const;

    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif
