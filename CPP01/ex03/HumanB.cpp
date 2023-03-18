#include "HumanB.hpp"

HumanB::HumanB(const string &name) : name(name), weapon(NULL) {}

HumanB::HumanB(const string &name, Weapon *weapon) : name(name), weapon(weapon) {}

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
        cout << name << " attacks with their " << weapon->getType() << endl;
    }
    else
    {
        cout << name << " hands up!" << endl;
    }
}
