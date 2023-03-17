#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "Debug: ";
    harl.complain("DEBUG");

    std::cout << "Warning: ";
    harl.complain("WARNING");

    std::cout << "Info: ";
    harl.complain("INFO");

    std::cout << "Error: ";
    harl.complain("ERROR");

    return (0);
}
