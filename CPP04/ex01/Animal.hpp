#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Animal
{
protected:
	string type;
	
public:
	Animal();
	Animal(const Animal &oth);
	virtual ~Animal();
	
	Animal &operator=(const Animal& oth);
	
	virtual void makeSound() const;
	string getType() const;
};

#endif
