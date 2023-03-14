#include "Zombie.hpp"

int main()
{
    Zombie zombie1 = Zombie("Darly");
    zombie1.announce();

    Zombie *zombie2 = newZombie("Rick");
    zombie2->announce();

    randomChump("Negan");

    delete zombie2;
    
    return (0);
}
