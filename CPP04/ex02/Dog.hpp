#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *beg;

public:
	Dog();
	Dog(const Dog &oth);
	~Dog();

	Dog	&operator=(const Dog &oth);
	
	virtual void makeSound() const;
};

#endif
