#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    string name;
    Weapon &weapon;

public:
    HumanA(const string &name, Weapon &weapon);
    void attack() const;
};

#endif
