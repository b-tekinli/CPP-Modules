#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clapTrap("Maggie");

    ScavTrap scavTrap("Carol");

    FragTrap fragTrap("Rosita");

    clapTrap.attack("enemy");
    scavTrap.takeDamage(5);
    fragTrap.attack("zombie");

    clapTrap.beRepaired(2);
    scavTrap.beRepaired(5);
    fragTrap.beRepaired(10);

    fragTrap.highFivesGuys();

    return (0);
}
