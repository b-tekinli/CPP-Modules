#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	cout << "Dog default constructor called." << endl;
	brain = new Brain();
}

Dog::Dog(const Dog &oth)
{
	*this = oth;
	cout << "Dog copy constuctor called." << endl;
}

Dog::~Dog()
{
	cout << "Dog destroyed." << endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &oth)
{
	type = oth.type;
	*this->brain = *oth.brain;
	cout << "Dog copy assigment operator called." << endl;

	return *this;
}

void Dog::makeSound() const
{
	cout << "Bark!" << endl;
}

Brain *Dog::getBrain() const
{
	return (brain);
}
