#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *address, std::size_t len, F func)
{
	std::size_t i = 0;
	while (i < len)
	{
		func(address[i]);
		i++;
	}
}

#endif
