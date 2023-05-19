#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const string &name)
    : name(name)
{
    for (int i = 0; i < 4; i++)
        this->materia[i] = NULL;
}

Character::Character(const Character &other)
    : name(other.name)
{
    for (int i = 0; i < 4; i++)
        this->materia[i] = (other.materia[i]) ? other.materia[i]->clone() : NULL;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->~Character();
        this->name = other.name;

        for (int i = 0; i < 4; i++)
            this->materia[i] = (other.materia[i]) ? other.materia[i]->clone() : NULL;
    }

    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        if (this->materia[i] != NULL)
            delete this->materia[i];
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    if (m)
        for (int i = 0; i < 4; i++)
            if (!this->materia[i])
            {
                this->materia[i] = m;
                break;
            }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
        this->materia[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx <= 3 && this->materia[idx])
        this->materia[idx]->use(target);
}
