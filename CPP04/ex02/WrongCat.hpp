#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &oth);
	~WrongCat();

	WrongCat &operator=(const WrongCat &oth);

	void makeSound() const;
};

#endif
