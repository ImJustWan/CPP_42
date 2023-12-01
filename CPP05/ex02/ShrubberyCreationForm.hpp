#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {

private:
	std::string const	_name;
	bool				_signed;
	int					_execGrade;
	int					_signGrade;


public:

	ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &);
	ShrubberyCreationForm(std::string name);
	~ShrubberyCreationForm();

	ShrubberyCreationForm	&operator=( ShrubberyCreationForm const & rhs );
	
	void				createShrubbery(std::string target);
	
	class OutfileOpening : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED "❌ Issues with outfile opening\n" _END);
			}
	};
};
