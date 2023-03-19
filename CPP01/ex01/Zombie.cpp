#include "Zombie.hpp"

Zombie::Zombie() { }

Zombie::Zombie(string name) : name(name)
{
    cout << "Zombie " << name << " is born!" << endl;
}

Zombie::~Zombie()
{
    cout << "Zombie " << name << " is dead!" << endl;
}

void Zombie::setName(string name)
{
    this->name = name;
}

void Zombie::announce()
{
    cout << "<" << name << "> Braiiiiiiinnnssss..." << endl;
}
