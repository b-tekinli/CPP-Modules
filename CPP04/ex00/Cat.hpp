#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &oth);
	~Cat();

	Cat &operator=(const Cat &oth);

	void makeSound() const;
};

#endif
