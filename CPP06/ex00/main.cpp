#include "Convert.hpp"

int main(int ac, char const *av[]) 
{
    if(ac != 2) {
        std::cout << "Usage: " << av[0] << "<literal>" << std::endl;
        return (1);
    }

    ScalarConverter::convert(av[1]);

    return (0);
}
