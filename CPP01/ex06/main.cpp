#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

    if (ac == 2)
    {
        int i = 0;

        string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

        while (i < 4 && av[1] != levels[i])
            i++;
        
        switch (i)
        {
        case 0:
            cout << "[" << levels[0] << "]" << endl;
            harl.complain(levels[0]);
            cout << endl;
        case 1:
            cout << "[" << levels[1] << "]" << endl;
            harl.complain(levels[1]);
            cout << endl;
        case 2:
            std::cout << "[" << levels[2] << "]" << endl;
            harl.complain(levels[2]);
            cout << endl;
        case 3:
            cout << "[" << levels[3] << "]" << endl;
            harl.complain(levels[3]);
            cout << endl;
        default:
            cout << "[ Probably complaining about insignificant problems ]" << endl;
        }
    }

    return (0);
}
