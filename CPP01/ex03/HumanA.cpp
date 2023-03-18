#include "HumanA.hpp"

HumanA::HumanA(const string &name, Weapon &weapon) : name(name), weapon(weapon) {}

void HumanA::attack() const
{
    cout << name << " attacks with their " << weapon.getType() << endl;
}
