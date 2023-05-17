#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	cout << "Cat default constructor called." << endl;
	brain = new Brain();
}

Cat::Cat(const Cat &oth)
{
	*this = oth;
	cout << "Cat copy constuctor called." << endl;
}

Cat::~Cat()
{
	delete brain;
	cout << "Cat destroyed." << endl;
}

Cat &Cat::operator=(const Cat &oth)
{
	type = oth.type;
	cout << "Cat copy assigment operator called." << endl;
	return (*this);
}

void Cat::makeSound() const
{
	cout << "Meow!" << endl;
}

Brain *Cat::getBrain() const
{
	return (brain);
}
