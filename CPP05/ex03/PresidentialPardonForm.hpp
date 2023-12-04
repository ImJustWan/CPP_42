#pragma once

#include <iostream>
#include "colors.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {

private:
	std::string const	_name;
	std::string const	_target;
	bool				_signed;
	int					_execGrade;
	int					_signGrade;


public:

	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();

	PresidentialPardonForm	&operator=( PresidentialPardonForm const & rhs );
	
	const std::string	&getName() const;
	const std::string	&getTarget() const;
	const int			&getExecGrade() const;
	const int			&getSignGrade() const;

	void				execute(Bureaucrat const & executor);
	
	class PresidentialDoom : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED "❌ Target could not find redemption\n" _END);
			}
	};
};

