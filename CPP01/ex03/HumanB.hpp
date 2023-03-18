#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    string name;
    Weapon *weapon;

public:
    HumanB(const string &name);
    HumanB(const string &name, Weapon *weapon);
    ~HumanB();
    void setWeapon(Weapon &weapon);
    void attack() const;
};

#endif
