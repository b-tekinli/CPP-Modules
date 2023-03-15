#include "Weapon.hpp"

Weapon::Weapon()
{
    this->type = "";
}

Weapon::Weapon(const std::string &type)
{
    setType(type);
}

const std::string &Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string &type)
{
    this->type = type;
}
