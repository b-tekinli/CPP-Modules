#include "Brain.hpp"

Brain::Brain()
{
	cout << "Brain default constructor called." << endl;
}

Brain::Brain(const Brain &oth)
{
	*this = oth;
	cout << "Brain copy constructor called." << endl;
}

Brain::~Brain()
{
	cout << "Brain destroyed." << endl;
}

Brain&	Brain::operator=(const Brain &oth)
{
	int	i;

	i = -1;
	while (++i < 100)
		this->ideas[i] = oth.ideas[i];

	cout << "Brain copy assigment operator called." << endl;

	return *this;
}
