#include "Intern.hpp"

Intern::Intern() {

	std::cout << _DARKGREY _ITALIC "Intern Constructor called" _END << std::endl;
	return;
}

Intern::Intern( Intern const & src ) {

	std::cout << _DARKGREY _ITALIC "Intern Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

Intern::~Intern(void) {

	std::cout << _DARKGREY _ITALIC "Intern Destructor called" _END << std::endl;
	return;
}

Intern & Intern::operator=( Intern const & rhs ) {
	
	std::cout << _DARKGREY _ITALIC "Intern Copy Assignement operator called" _END << std::endl;
	if (this == &rhs)
		return (*this);
	return *this;
}

AForm		*Intern::makeForm(std::string formName, std::string target) {
	std::string formz[3] = {"scf", "rrf", "ppf"};
	// void(functionPtr[3])(std::string) = {ShrubberyCreationForm(target), &Harl::info, &Harl::warning, &Harl::error};

	int i;
	for (i = 0; i < 3; i++)
		if (formName == formz[i])
			break; 
	switch ( i )
	{
		case 0: {
			return (new ShrubberyCreationForm(target));
		}
		case 1: {
			return (new RobotomyRequestForm(target));
		}
		case 2: {
			return (new PresidentialPardonForm(target));
		}
		default:
		{
			std::cout << _MAROON _BOLD "You tried to ask for a form : \"" << formName << "\", no can do ! \n" _END << std::endl;
			throw UnknownForm();
		}
	}
	return 0;
}
