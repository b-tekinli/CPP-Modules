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

Brain &Brain::operator=(const Brain &oth)
{
	if (this != &oth)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = oth.ideas[i];
		}
	}

	cout << "Brain copy assigment operator called." << endl;

	return (*this);
}

const string &Brain::getIdea(int idx) const
{
	return (ideas[idx]);
}
