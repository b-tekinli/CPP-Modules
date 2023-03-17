#ifndef CPP_MODULE_HARL_H
#define CPP_MODULE_HARL_H

#include "string"
#include "iostream"

class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    Harl();
    ~Harl();
    void complain(std::string level);
};

#endif
