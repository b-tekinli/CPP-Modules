#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL) {}

HumanB::HumanB(const std::string &name, Weapon *weapon) : name(name), weapon(weapon) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
    if (this->weapon != NULL)
    {
        delete this->weapon;
    }
    this->weapon = &weapon;
}

void HumanB::attack() const
{
    if (weapon != NULL)
    {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
    else
    {
        std::cout << name << " hands up!" << std::endl;
    }
}
