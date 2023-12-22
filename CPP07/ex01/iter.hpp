#pragma once

#include "colors.hpp"
#include <iostream>

template < typename T >
void	iter(T *arr, size_t size, void (*foo)(T &))
{
	if (arr == NULL || size == 0 || foo == NULL) {
		std::cout << _SALMON "\nCannot execute iter .(• ᴖ • .)\n" _END << std::endl;
		return;
	}
	for (size_t i = 0; i < size; i++)
		foo(arr[i]);
}
