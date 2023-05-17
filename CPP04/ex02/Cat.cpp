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
	cout << "Cat destroyed." << endl;
	delete brain;
}

Cat &Cat::operator=(const Cat &oth)
{
	type = oth.type;
	*this->brain = *oth.brain;
	cout << "Cat copy assigment operator called." << endl;

	return (*this);
}

void Cat::makeSound() const
{
	cout << "Meow!" << endl;
}
