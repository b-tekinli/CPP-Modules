#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	cout << "Animal default constructor called." << endl;
}

Animal::Animal(const Animal &oth)
{
	*this = oth;
	cout << "Animal copy constructor called." << endl;
}

Animal::~Animal()
{
	cout << "Animal destroyed." << endl;
}

Animal &Animal::operator=(const Animal &oth)
{
	type = oth.type;
	cout << "Animal copy assigment operator called." << endl;

	return (*this);
}

void Animal::makeSound() const
{
	cout << "The Animal Sound" << endl;
}

string Animal::getType() const
{
	return type;
}
