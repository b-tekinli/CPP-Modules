#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog();
	Dog(const Dog &oth);
	~Dog();

	Dog &operator=(const Dog &oth);

	void makeSound() const;
	Brain *getBrain() const;
};

#endif
