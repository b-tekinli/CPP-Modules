#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

    if (ac == 2)
    {
        int i = 0;

        std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

        while (i < 4 && av[1] != levels[i])
            i++;
        
        switch (i)
        {
        case 0:
            std::cout << "[" << levels[0] << "]" << std::endl;
            harl.complain(levels[0]);
            std::cout << std::endl;
        case 1:
            std::cout << "[" << levels[1] << "]" << std::endl;
            harl.complain(levels[1]);
            std::cout << std::endl;
        case 2:
            std::cout << "[" << levels[2] << "]" << std::endl;
            harl.complain(levels[2]);
            std::cout << std::endl;
        case 3:
            std::cout << "[" << levels[3] << "]" << std::endl;
            harl.complain(levels[3]);
            std::cout << std::endl;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        }
    }

    return (0);
}
