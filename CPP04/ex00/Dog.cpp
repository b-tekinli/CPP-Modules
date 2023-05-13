#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	cout << "Dog default constructor called." << endl;
}

Dog::Dog(const Dog &oth)
{
	*this = oth;
	cout << "Dog copy constuctor called." << endl;
}

Dog::~Dog()
{
	cout << "Dog destroyed." << endl;
}

Dog &Dog::operator=(const Dog &oth)
{
	type = oth.type;
	cout << "Dog copy assigment operator called." << endl;

	return *this;
}

void Dog::makeSound() const
{
	cout << "Bark!" << endl;
}
