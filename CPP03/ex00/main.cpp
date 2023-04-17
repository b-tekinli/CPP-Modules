#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap;
    ClapTrap otherClapTrap("Negan");
    ClapTrap test(clapTrap);

    clapTrap.attack("enemy");
    otherClapTrap.takeDamage(5);
    clapTrap.beRepaired(2);

    clapTrap.attack("zombie");
	otherClapTrap.takeDamage(4);
	test.beRepaired(10);
    
	clapTrap = otherClapTrap;

    return 0;
}
