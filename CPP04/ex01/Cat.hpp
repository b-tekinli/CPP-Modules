#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *beg;
public:
	Cat();
	Cat(const Cat &oth);
	~Cat();

	void operator=(const Cat& oth);
	
	virtual void makeSound() const;
};

#endif
