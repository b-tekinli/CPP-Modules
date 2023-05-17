#include "Brain.hpp"

Brain::Brain()
{
	 const std::string examples[] = {
        "I want to sleep",
        "I want to food",
        "I want pets",
        "I want to go for a walk",
        "I want water",
        "I want a treat",
    };

    for (int i = 0; i < 100; i++)
        this->ideas[i] = examples[rand() % (sizeof(examples) / sizeof(string))];
	
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

	for (int i = 0; i < 100; i++)
	{
		ideas[i] = oth.ideas[i];
	}

	cout << "Brain copy assigment operator called." << endl;

	return (*this);
}

const string &Brain::getIdea(int idx) const
{
	return ideas[idx];
}
