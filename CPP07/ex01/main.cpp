#include "iter.hpp"

int main()
{
	char name[6] = "beyza";
	iter(name, 6, print);


	int arr[5] = {1, 12, 4, 7, 5};
	iter(arr, 5, print);

	return (0);
}
