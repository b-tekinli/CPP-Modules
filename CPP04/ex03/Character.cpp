#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const string &name)
    : name(name)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const Character &other)
    : name(other.name)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = (other.inventory[i]) ? other.inventory[i]->clone() : NULL;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->~Character();
        this->name = other.name;
        for (int i = 0; i < 4; i++)
            this->inventory[i] = (other.inventory[i]) ? other.inventory[i]->clone() : NULL;
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        if (this->inventory[i] != NULL)
            delete this->inventory[i];
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    if (m)
        for (int i = 0; i < 4; i++)
            if (!this->inventory[i])
            {
                this->inventory[i] = m;
                break;
            }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
        this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx <= 3 && this->inventory[idx])
        this->inventory[idx]->use(target);
}