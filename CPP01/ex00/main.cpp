#include "Zombie.hpp"

int main()
{
    Zombie zombieA = Zombie("Zombie A");
    zombieA.announce();

    Zombie *zombieB = newZombie("Zombie B");
    zombieB->announce();

    randomChump("Zombie Y");

    delete zombieB;
    
    return (0);
}
