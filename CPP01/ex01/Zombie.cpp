#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() { }

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "Zombie " << _name << " is born!" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " is dead!" << std::endl;
}

void Zombie::announce()
{
    std::cout << "<" << _name << "> Braiiiiiiinnnssss..." << std::endl;
}
