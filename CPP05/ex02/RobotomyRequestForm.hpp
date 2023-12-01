#pragma once

#include <iostream>
#include "colors.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {

private:
	std::string const	_name;
	bool				_signed;
	int					_execGrade;
	int					_signGrade;


public:

	RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &);
	RobotomyRequestForm(std::string name);
	~RobotomyRequestForm();

	RobotomyRequestForm	&operator=( RobotomyRequestForm const & rhs );
	
	void				robotomization(std::string target);
	
	class RobotFailed : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED "❌ Target could not be robotized\n" _END);
            }
	};
};

