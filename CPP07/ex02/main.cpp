#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	std::cout << _GREY "\n🔹 Are mirror and numbers identical ? 🔹\n" _END << std::endl;

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "At index " << i;
			std::cerr << ", mirror and numbers didn't save the same value!!" << std::endl;
			break;
		}
		if (i == MAX_VAL - 1)
			std::cout << _AQUAMARINE "Yay, they are !\n" << std::endl;
	}

	std::cout << _GREY "\n🔹 Changing number at index[88] 🔹\n" _END << std::endl;
	numbers[88] += 88;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "At index " << i;
			std::cerr << ", mirror and numbers didn't save the same value!!\n" << std::endl;
			break;
		}
	}

	std::cout << _GREY "\n🔹 Trying wrong indexes ! 🔹\n" _END << std::endl;
	try
	{
		std::cout << _RIVIERA _ITALIC "Changing value at index 42 to 42 !\n" _END << std::endl;
		std::cout << "Before : numbers[42] = " << numbers[42] << std::endl;
		numbers[42] = 42;
		std::cout << "After  : numbers[42] = " << numbers[42] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << _GREY "\n\n🔹 Trying wrong indexes ! 🔹\n" _END << std::endl;
	try
	{
		numbers[-2] = 0;
		std::cout << "numbers[-2] = " << numbers[-2] << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
		std::cout << "numbers[MAX_VAL] = " << numbers[MAX_VAL] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete [] mirror;
	return 0;
}