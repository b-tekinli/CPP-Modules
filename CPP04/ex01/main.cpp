#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// int main()
// {
// 	Animal *animals[6];

// 	for (int i = 0; i < 3; ++i)
// 	{
// 		cout << "dog: " << i << endl;
// 		animals[i] = new Dog();
// 	}

// 	for (int i = 3; i < 6; ++i)
// 	{
// 		cout << "cat: " << i << endl;
// 		animals[i] = new Cat();
// 	}

// 	for (int i = 0; i < 6; ++i)
// 	{
// 		cout << "destruct: " << i << endl;
// 		delete animals[i];
// 	}

// 	return (0);
// }

#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>

int main()
{
	Animal *animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i >= 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	Cat copy(*(Cat *)animals[0]);

	cout << endl;
	
	for (int i = 0; i < 100; i++)
	{
		cout << setw(30) << left << copy.getBrain()->getIdea(i);
		cout << setw(30) << left << ((Cat *)animals[0])->getBrain()->getIdea(i) << endl;
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
	}
	// system("leaks Animals");
}
