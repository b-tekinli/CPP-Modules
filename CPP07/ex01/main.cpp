#include "iter.hpp"
#include <iostream>


int main(void)
{
	char name[7] = "beyzat";
	iter(name, 7, print);

	std::cout << std::endl;

	int arr[5] = {5, 12, 4, 8, 10};
	iter(arr, 5, print);
}
