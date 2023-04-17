#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    name = "Daryl";
	hitPoints = 100;
	attackDamage = 30;
	energyPoints = 100;
	cout << "ClapTrap called." << endl;
    cout << "FragTrap " << name << " is ready to cause some damage!" << endl;
}

FragTrap::FragTrap(const string name) : ClapTrap(name)
{
	hitPoints = 100;
	attackDamage = 30;
	energyPoints = 100;
    cout << "FragTrap " << name << " is ready to cause some damage!" << endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    cout << "FragTrap " << name << " is ready to cause some damage!" << endl;
    *this  = other;
}

FragTrap::~FragTrap()
{
    cout << "FragTrap " << name << " is dead!" << endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        cout << "FragTrap copy assigment operator called." << endl;
    }
    
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    cout << "FragTrap " << name << " wants to give you a high five!" << endl;
}
