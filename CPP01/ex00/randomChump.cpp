#include "Zombie.hpp"

void randomChump(string name)
{
    Zombie zombie = Zombie(name);
    zombie.announce();
}
