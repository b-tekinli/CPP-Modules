#include "Harl.hpp"

void Harl::complain(std::string level)
{
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    void (Harl::*comments[4])();

    comments[0] = &Harl::debug;
    comments[1] = &Harl::info;
    comments[2] = &Harl::warning;
    comments[3] = &Harl::error;

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            (this->*comments[i])();
    }
}

void Harl::debug()
{
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
