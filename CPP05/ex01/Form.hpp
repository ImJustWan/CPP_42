#pragma once

#include <iostream>
#include <string>
#include "colors.hpp"

class Form {

private:
	std::string const	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;

public:
	Form();
	Form( Form const &);
	Form(std::string name, int grade);
	Form &operator=( Form const &);
	~Form();

	const std::string	&getName() const;
	const int			&getGrade() const;
	void				incrementGrade();
	void				decrementGrade();

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return("This is too high ! Grade can only be between 1 and 150.");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return("This is too low ! Grade can only be between 1 and 150.");
			}
	};

};

std::ostream & operator<<( std::ostream & o, Form const & rhs );
