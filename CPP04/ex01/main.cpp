#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animals[6];

	for (int i = 0; i < 3; ++i)
	{
		cout << "dog: " << i << endl;
		animals[i] = new Dog();
	}

	for (int i = 3; i < 6; ++i)
	{
		cout << "cat: " << i << endl;
		animals[i] = new Cat();
	}

	for (int i = 0; i < 6; ++i)
	{
		cout << "destruct: " << i << endl;
		delete animals[i];
	}

	return (0);
}
