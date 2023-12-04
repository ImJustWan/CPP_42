#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << _BOLD _GREY "\n🔹 Creating Bureaucrats ! 🔹\n" _END << std::endl;
	Bureaucrat Garou("Garou", 8);
	std::cout << Garou << std::endl;

	std::cout << _BOLD _GREY "\n🔹 Creating Forms ! 🔹\n" _END << std::endl;
	const AForm* shrubbers  = new ShrubberyCreationForm();
	const AForm* guineaPig  = new RobotomyRequestForm();
	const AForm* inmate  = new PresidentialPardonForm();

	std::cout << _BOLD _GREY "\n\n🔹 Can our Bureaucrat execute those forms ? 🔹\n" _END << std::endl;

	try {
		Garou.executeForm(*shrubbers);
		Garou.executeForm(*guineaPig);
		Garou.executeForm(*inmate);
	}
	catch(const Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what();
	}


	delete shrubbers;
	delete guineaPig;
	delete inmate;
	return 0;
}
