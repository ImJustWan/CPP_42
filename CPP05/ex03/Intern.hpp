#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern {

public:

	Intern();
	Intern(Intern const & src);
	~Intern();

	Intern 		&operator=( Intern const & rhs );

	AForm		*makeForm(std::string formName, std::string target);

	class UnknownForm : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED "❌ Intern only knows the forms \n  - scf\n  - rrf\n  - ppf \n\nヽ༼ ಠ_ಠ༽ﾉ\n\n" _END);
			}
	};
};
