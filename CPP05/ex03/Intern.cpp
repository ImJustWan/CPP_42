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

	AForm	*magic[3] = {
			new ShrubberyCreationForm(target),
			new RobotomyRequestForm(target),
			new PresidentialPardonForm(target)
	};

	AForm *final = NULL;
	for (int i = 0; i < 3; i++)
		if (formName == formz[i])
			final = magic[i];
		else
			delete magic[i];

	if (final != NULL) {
		std::cout << _BOLD _AQUAMARINE "\nForm successfully created by our fav Intern ᕙ(  •̀ ᗜ •́  )ᕗ \n" _END << std::endl;
		return final;
	}
	else {
		std::cout << _MAROON _BOLD "You tried to ask for a form : \"" << formName << "\", no can do ! \n" _END << std::endl;
		throw UnknownForm();
	}
}
