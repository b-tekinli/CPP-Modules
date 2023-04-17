#include "ScavTrap.hpp"

int	 main(void)
{
	ScavTrap scavTrap("Rick");
	ScavTrap otherScavTrap("Negan");
	ScavTrap test(otherScavTrap);

	scavTrap.attack("zombie");
	otherScavTrap.takeDamage(2);
	test.beRepaired(10);

	scavTrap = otherScavTrap;

	scavTrap.attack("zombie");
	otherScavTrap.guardGate();
}
