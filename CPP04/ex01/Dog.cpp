#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	cout << "Dog default constructor called." << endl;
	beg = new Brain();
}

Dog::Dog(const Dog &oth)
{
	*this = oth;
	cout << "Dog copy constuctor called." << endl;
}

Dog::~Dog()
{
	cout << "Dog destroyed." << endl;
	delete beg;
}

void Dog::operator=(const Dog &oth)
{
	type = oth.type;
	cout << "Dog copy assigment operator called." << endl;
}

void Dog::makeSound() const
{
	cout << "Bark!" << endl;
}
