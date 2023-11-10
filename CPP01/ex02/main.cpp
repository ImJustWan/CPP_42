#include <iostream>
#include <string>

int main() {

	std::string		Radiants = "HI THIS IS BRAIN";
	std::string*	RadiantsPTR = &Radiants;
	std::string&	RadiantsREF = Radiants;

	std::cout << "String address is: " << &Radiants << std::endl;
	std::cout << "StringPTR address is: " << &RadiantsPTR << std::endl;
	std::cout << "StringREF address is: " << &RadiantsREF << std::endl;

	std::cout << "\nString value is: " << Radiants << std::endl;
	std::cout << "StringPTR value is: " << *RadiantsPTR << std::endl;
	std::cout << "StringREF value is: " << RadiantsREF << std::endl;

	return 0;
}
