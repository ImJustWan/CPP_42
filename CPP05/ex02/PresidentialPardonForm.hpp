#pragma once

#include <iostream>
#include "colors.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {

private:
	std::string const	_name;
	bool				_signed;
	int					_execGrade;
	int					_signGrade;


public:

	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &);
	PresidentialPardonForm(std::string name);
	~PresidentialPardonForm();

	PresidentialPardonForm	&operator=( PresidentialPardonForm const & rhs );
	
	virtual const std::string	&getName() const;
	virtual const int			&getExecGrade() const;
	virtual const int			&getSignGrade() const;

	void					amnesty(std::string target);
	
	class PresidentialDoom : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED "❌ Target could not find redemption\n" _END);
			}
	};
};

