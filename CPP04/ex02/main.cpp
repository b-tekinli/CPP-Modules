#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Cat *catObject = new Cat;
	Dog *dogObject = new Dog;
	Dog *duckObject = new Dog;

	Animal *animalObjects[] = { catObject, dogObject, duckObject };

	for (int i = 0; i < 3; i++)
		animalObjects[i]->makeSound();

	delete catObject;
	delete dogObject;
	delete duckObject;
}
