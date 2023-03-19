#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Zombie
{
private:
    string name;

public:
    Zombie();
    Zombie(string name);
    ~Zombie();
    void announce();
};

Zombie *zombieHorde(int N, string name);

#endif
