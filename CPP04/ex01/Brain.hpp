#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Brain
{
private:
    string ideas[100];

public:
    Brain();
    Brain(const Brain &oth);
    ~Brain();

    Brain &operator=(const Brain &oth);

    const string &getIdea(int idx) const;
};

#endif
