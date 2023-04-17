#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("Bob");
    ClapTrap otherClapTrap("Joe");

    clapTrap.attack("enemy");
    otherClapTrap.takeDamage(5);
    clapTrap.beRepaired(2);
    clapTrap.attack("enemy");
    otherClapTrap.takeDamage(10);
    clapTrap.attack("enemy");
    clapTrap.beRepaired(5);
    clapTrap.attack("enemy");

    return 0;
}
