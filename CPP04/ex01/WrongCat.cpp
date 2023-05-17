#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	cout << "WrongCat default constructor called." << endl;
}

WrongCat::WrongCat(const WrongCat &oth)
{
	*this = oth;
	cout << "WrongCat copy constructor called." << endl;
}

WrongCat::~WrongCat()
{
	cout << "WrongCat destroyed." << endl;
}

void WrongCat::operator=(const WrongCat &oth)
{
	type = oth.type;
	cout << "WrongCat copy assigment operator called." << endl;
}

void WrongCat::makeSound() const
{
	cout << "Wrong Meow!" << endl;
}
