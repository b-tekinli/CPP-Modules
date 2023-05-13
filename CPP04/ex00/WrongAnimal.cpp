#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	cout << "WrongAnimal default constructor called." << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &oth)
{
	*this = oth;
	cout << "WrongAnimal copy constructor called." << endl;
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal destroyed." << endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &oth)
{
	type = oth.type;
	cout << "WrongAnimal copy assigment operator called." << endl;

	return *this;
}

void WrongAnimal::makeSound() const
{
	cout << "WrongAnimal Sound" << endl;
}

string WrongAnimal::getType() const
{
	return (type);
}
