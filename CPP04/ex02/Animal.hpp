#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

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

	virtual void makeSound() const = 0;
	string getType() const;
};

#endif
