#include "Weapon.hpp"

Weapon::Weapon()
{
    this->type = "";
}

Weapon::Weapon(const string &type)
{
    setType(type);
}

const string &Weapon::getType() const
{
    return type;
}

void Weapon::setType(const string &type)
{
    this->type = type;
}
