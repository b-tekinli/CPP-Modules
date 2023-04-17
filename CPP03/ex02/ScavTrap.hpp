#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const string name);
    ScavTrap(const ScavTrap &other);
    ~ScavTrap();

    ScavTrap &operator=(const ScavTrap &other);

    void attack(const string &target);
    void guardGate();
};
