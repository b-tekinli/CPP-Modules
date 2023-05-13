#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class WrongAnimal
{
protected:
	string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &oth);
	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &oth);

	void makeSound() const;
	string getType() const;
};

#endif
