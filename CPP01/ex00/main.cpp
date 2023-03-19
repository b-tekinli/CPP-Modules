#include "Zombie.hpp"

int main()
{
    Zombie zombie1 = Zombie("Darly");
    zombie1.announce();

    Zombie *zombie2 = newZombie("Rick");
    zombie2->announce();
    
    delete zombie2;

    randomChump("Negan");

    randomChump("Carol");

    Zombie zombie3 = Zombie("Rosita");
    zombie3.announce();

    Zombie zombie4 = Zombie("Glenn");
    zombie4.announce();

    randomChump("Maggie");

    return (0);
}
