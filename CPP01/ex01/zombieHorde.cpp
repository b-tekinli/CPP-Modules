#include "Zombie.hpp"

Zombie *zombieHorde(int N, string name)
{
    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);

        if(i == 0) {
            horde[i].setName(name + " Carl");
        } else if (i == 1) {
            horde[i].setName(name + " Judith");
        } else if (i == 2) {
            horde[i].setName(name + " Aaron");
        }
    }

    return horde;
}
