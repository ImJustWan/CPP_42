#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << _BOLD _GREY "\n🔹 Creating Bureaucrats ! 🔹\n" _END << std::endl;
	Bureaucrat JJG("Jean-Jacques Goldman", 148);
	std::cout << JJG << std::endl;
	Bureaucrat Garou("Garou", 1);
	std::cout << Garou << std::endl;

	std::cout << _BOLD _GREY "\n🔹 Creating Forms ! 🔹\n" _END << std::endl;
	const AForm* shrubbers  = new ShrubberyCreationForm("Home");
	try {
			std::cout << _BOLD _GREY "\n🔹 Creating a small forest 🌳🌳🌳 🔹\n" _END << std::endl;
			((ShrubberyCreationForm *)shrubbers)->execute(JJG);
	}
	catch(const ShrubberyCreationForm::OutfileOpening &e) {
		std::cout << e.what();
	}

	std::cout << std::endl;

	const AForm* guineaPig  = new RobotomyRequestForm("Metamorph");
	try {
			std::cout << _BOLD _GREY "\n🔹 Trying to create a Robot ! 🤖🔹\n" _END << std::endl;
			((RobotomyRequestForm *)guineaPig)->execute(Garou);
	}
	catch(const RobotomyRequestForm::RobotFailed &e) {
		std::cout << e.what();
	}

	std::cout << "\n" << std::endl;

	const AForm* inmate  = new PresidentialPardonForm("Ruby-Rose");
	try {
			std::cout << _BOLD _GREY "\n🔹 Asking for redemption 🕊️ 🔹\n" _END << std::endl;
			((PresidentialPardonForm *)inmate)->execute(Garou);
	}
	catch(const PresidentialPardonForm::PresidentialDoom &e) {
		std::cout << e.what();
	}

	std::cout << _BOLD _GREY "\n\n🔹 Can our Bureaucrats execute those forms ? 🔹\n" _END << std::endl;
	std::cout << _GREY "Garou goes first ~\n" _END << std::endl;

	try {
		Garou.executeForm(*shrubbers);
		Garou.executeForm(*guineaPig);
		Garou.executeForm(*inmate);
	}
	catch(const Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what();
	}

	std::cout << _GREY "\nJJG's turn !\n" _END << std::endl;

	try {
		JJG.executeForm(*shrubbers);
		JJG.executeForm(*guineaPig);
		JJG.executeForm(*inmate);
	}
	catch(const Bureaucrat::GradeTooLowException &e) {
	}
	delete shrubbers;
	delete guineaPig;
	delete inmate;
	return 0;
}
