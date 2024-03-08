#include "iter.hpp"

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main()
{
	char name[6] = "beyza";
	iter(name, 6, print<char>);

	int arr[5] = {1, 12, 4, 7, 5};
	
	iter(arr, 5, print<int>);



	return (0);
}
