#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;

class Animal
{
protected:
	string type;

public:
	Animal();
	Animal(const Animal &oth);
	virtual ~Animal();

	Animal &operator=(const Animal &oth);

	virtual void makeSound() const;
	string getType() const;
};

#endif
