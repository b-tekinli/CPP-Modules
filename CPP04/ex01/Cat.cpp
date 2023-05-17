#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	cout << "Cat default constructor called." << endl;
	beg = new Brain();
}

Cat::Cat(const Cat &oth)
{
	*this = oth;
	cout << "Cat copy constuctor called." << endl;
}

Cat::~Cat()
{
	cout << "Cat destroyed." << endl;
	delete beg;
}

void Cat::operator=(const Cat &oth)
{
	type = oth.type;
	cout << "Cat copy assigment operator called." << endl;
}

void Cat::makeSound() const
{
	cout << "Meow!" << endl;
}
