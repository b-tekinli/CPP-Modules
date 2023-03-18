#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Weapon
{
private:
    string type;

public:
    Weapon();
    Weapon(const string &type);
    const string &getType() const;
    void setType(const string &type);
};

#endif
