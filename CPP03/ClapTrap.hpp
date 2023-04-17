#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class ClapTrap
{
private:
    string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
    ClapTrap(string name);
    ~ClapTrap();
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
