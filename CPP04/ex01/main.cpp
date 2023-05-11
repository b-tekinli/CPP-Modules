#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	{
		const Animal* meta = new Animal(); 	
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		cout << j->getType() << " " << endl;
		cout << i->getType() << " " << endl;

		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete	meta;
		delete	j;
		delete	i;
	}
	
	cout << "\n\n\n\n" << endl;
	
	{
		const WrongAnimal* meta = new WrongAnimal(); 
		const WrongAnimal* i = new WrongCat();
		
		cout << i->getType() << " " << endl;
		i->makeSound();
		meta->makeSound();

		delete	meta;
		delete	i;
	}
	
	return (0);
}
