#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon weaponA("M416");
    HumanA humanA("Ahmet", weaponA);
    humanA.attack();

    HumanB humanB("Beyza");
    humanB.attack();

    Weapon *weaponB = new Weapon("AK47");
    HumanB humanB2("Mehmet", weaponB);
    humanB2.attack();

    Weapon weaponC("Glock");
    humanB.setWeapon(weaponC);
    humanB.attack();

    delete weaponB;

    return (0);
}
