#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    name = "Beyza";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    cout << "Default ClapTrap is alive!" << endl;
}

ClapTrap::ClapTrap(string name) : name(name),
                                  hitPoints(10),
                                  energyPoints(10),
                                  attackDamage(0)
{
    cout << "ClapTrap " << name << " is alive!" << endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name),
                                             hitPoints(other.hitPoints),
                                             energyPoints(other.energyPoints),
                                             attackDamage(other.attackDamage)
{
    cout << "ClapTrap " << name << " is alive! (copy)" << endl;
}

ClapTrap::~ClapTrap()
{
    cout << "ClapTrap " << name << " is dead!" << endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const string &target)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        cout << "ClapTrap " << name << " cannot attack because it has no hit points or energy points left." << endl;
        return;
    }

    cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << endl;
    energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        cout << "ClapTrap " << name << " cannot take damage because it has no hit points left." << endl;
        return;
    }

    cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << endl;
    hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0)
    {
        cout << "ClapTrap " << name << " cannot be repaired because it has no hit points left." << endl;
        return;
    }

    cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << endl;
    hitPoints += amount;
    energyPoints--;
}
