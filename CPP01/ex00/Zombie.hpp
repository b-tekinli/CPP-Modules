#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Zombie
{
private:
    string name;

public:
    Zombie(string name);
    ~Zombie();
    void announce();
};

Zombie *newZombie(string name);
void randomChump(string name);

#endif
