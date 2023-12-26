#include "easyfind.hpp"
#include <vector>
#include <cstdlib> 

void displayInt(int i) {
	std::cout << i << std::endl;
}

int generateRandomNumber() {
	return rand() % 201 - 100;
}

int main()
{
	std::vector<int>			myVector;
	std::vector<int>::iterator	res;

	for (int i = 42; i < 89; i++) {
		myVector.push_back(i);
	}
	try {
		std::cout << _GREY "\n🔹 Is the value '88' in this vector ? 🔹\n" _END << std::endl;
		res = easyfind(myVector, 88);
		std::cout << _AQUAMARINE _BOLD "Yes it's in ! ৻(  •̀ ᗜ •́  ৻)\n" _END << std::endl;

		std::cout << _GREY "\n🔹 Is the value '20' in this vector ? 🔹\n" _END << std::endl;
		res = easyfind(myVector, 20);
		std::cout << _AQUAMARINE _BOLD "Yes it's in ! ৻(  •̀ ᗜ •́  ৻)\n" _END << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what()  << std::endl;
	}


	std::cout << _GREY "\n🔹 Filling the vector with 50 random numbers from -100 to 100🔹\n" _END << std::endl;

	srand(static_cast<unsigned>(time(0)));
	for (int i = 0; i < 50; ++i) {
		myVector.push_back(generateRandomNumber());
	}

	int		test1 = generateRandomNumber();
	int		test2 = generateRandomNumber();
	int		test3 = generateRandomNumber();
	std::cout << _ITALIC _GREY "\nAre the values '" << test1 << "', '" << test2 << "' or '";
	std::cout << test3 << "' in this vector ? \n" _END << std::endl;
	try {

		res = easyfind(myVector, test1);
		std::cout << _AQUAMARINE _BOLD "Yes, test1 is in ! ৻(  •̀ ᗜ •́  ৻)\n" _END << std::endl;
		res = easyfind(myVector, test2);
		std::cout << _AQUAMARINE _BOLD "Yes, test2 is in ! ৻(  •̀ ᗜ •́  ৻)\n" _END << std::endl;
		res = easyfind(myVector, test3);
		std::cout << _AQUAMARINE _BOLD "Yes, test3 is in ! ৻(  •̀ ᗜ •́  ৻)\n" _END << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what()  << std::endl;
	}
	// Seed the random number generator with the current time

	// Fill myVector with 50 random values between -100 and 100

	std::cout << _GREY "\n🔹 For clarity, here is the vector :🔹\n" _END << std::endl;
	
	for(res = myVector.begin(); res != myVector.end(); res++) {
		if (*res == test1 || *res == test2 || *res == test3)
			std::cout << _RIVIERA _BOLD;
		if (res != myVector.end() - 1)
			std::cout << *res << _END ", ";
		else
			std::cout << *res << _END << std::endl;
	}

	return 0;
}
