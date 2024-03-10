#include "easyfind.hpp"

int main()
{

    std::vector<int> container;

    for (int i = 1; i <= 10; i++)
        container.push_back(i);

    for (int i = 0; i < 10; i++)
        std::cout << " " << container.at(i);

    std::cout << std::endl;

    srand(time(NULL));

    int value = (rand() % 10) + 1;

    std::cout << "our value => " << value;
    if (easyfind(container, value) != -1)
        std::cout << " is founded to easily " << std::endl;
    else
        std::cout << " is not found by my easyfind dunction " << std::endl;
}
