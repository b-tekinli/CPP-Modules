#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class WrongAnimal
{
protected:
	string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &oth);
	virtual ~WrongAnimal();

	void operator=(const WrongAnimal &oth);

	virtual void makeSound() const;
	string getType() const;
};

#endif
