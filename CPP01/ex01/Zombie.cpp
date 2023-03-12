#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() { }

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << "Zombie " << name << " is born!" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " is dead!" << std::endl;
}

void Zombie::announce()
{
    std::cout << "<" << name << "> Braiiiiiiinnnssss..." << std::endl;
}
