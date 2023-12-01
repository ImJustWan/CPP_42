#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	// std::cout << _BOLD _GREY "\n🔹 Creating Bureaucrats ! 🔹\n" _END << std::endl;
	// Bureaucrat JJG("Jean-Jacques Goldman", 88);
	// std::cout << JJG << std::endl;
	// Bureaucrat Garou("Garou", 8);
	// std::cout << Garou << std::endl;

	std::cout << _BOLD _GREY "\n🔹 Creating Forms ! 🔹\n" _END << std::endl;
	ShrubberyCreationForm shrubbers;
	try {
			std::cout << _BOLD _GREY "\n🔹 Creating a small forest 🌳🌳🌳 🔹\n" _END << std::endl;
			shrubbers.createShrubbery("targetFile");
	}
	catch(const ShrubberyCreationForm::OutfileOpening &e) {
		std::cout << e.what();
	}

	RobotomyRequestForm guineaPig;
	try {
			std::cout << _BOLD _GREY "\n🔹 Trying to create a Robot ! 🤖🔹\n" _END << std::endl;
			guineaPig.robotomization("Metamorph");
	}
	catch(const RobotomyRequestForm::RobotFailed &e) {
		std::cout << e.what();
	}
	return 0;
}
