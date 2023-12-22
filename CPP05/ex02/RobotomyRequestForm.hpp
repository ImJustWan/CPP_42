#pragma once

#include <iostream>
#include "colors.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {

private:
	std::string const	_name;
	std::string const	_target;
	bool				_signed;
	int					_execGrade;
	int					_signGrade;


public:

	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();

	RobotomyRequestForm	&operator=( RobotomyRequestForm const & rhs );
	
	virtual const std::string	&getName() const;
	virtual const std::string	&getTarget() const;
	virtual const int			&getExecGrade() const;
	virtual const int			&getSignGrade() const;

	void						executeAction(Bureaucrat const & executor);

	class RobotFailed : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				
				return(_RED _BOLD "❌ Target could not be robotized\n" _END);
			}
	};
};

