#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    cout << this->name << " has been destroyed." << endl;
}

void Zombie::announce()
{
    cout << this->name << ": BraiiiiiiinnnzzzZ..." << endl;
}
