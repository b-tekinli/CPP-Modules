#include "Harl.hpp"

int main()
{
    Harl harl;

    cout << "Debug: ";
    harl.complain("DEBUG");

    cout << "Warning: ";
    harl.complain("WARNING");

    cout << "Info: ";
    harl.complain("INFO");

    cout << "Error: ";
    harl.complain("ERROR");

    return (0);
}
