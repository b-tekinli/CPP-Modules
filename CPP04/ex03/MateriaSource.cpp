#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->materia[i] = NULL;

    return;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
        this->materia[i] = (other.materia[i]) ? other.materia[i]->clone() : NULL;

    return;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        this->~MateriaSource();
        for (int i = 0; i < 4; i++)
            this->materia[i] = other.materia[i] ? other.materia[i]->clone() : NULL;
    }

    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (this->materia[i])
            delete this->materia[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (m)
        for (int i = 0; i < 4; i++)
            if (!this->materia[i])
            {
                this->materia[i] = m;
                break;
            }
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < 4; i++)
        if (this->materia[i] && this->materia[i]->getType() == type)
            return (this->materia[i]->clone());

    return (NULL);
}
