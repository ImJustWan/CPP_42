#pragma once

#include <iostream>
#include <string>
#include "colors.hpp"

class Bureaucrat {

private:
	std::string const	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &);
	Bureaucrat(std::string name, int grade);
	Bureaucrat &operator=(Bureaucrat const &);
	~Bureaucrat();

	const std::string	&getName() const;
	const int			&getGrade() const;
	void				incrementGrade();
	void				decrementGrade();

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_BOLD _LIGHTGREY "This is too high ! Grade can only be between 1 and 150." _END);
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_BOLD _LIGHTGREY "This is too low ! Grade can only be between 1 and 150." _END);
			}
	};

};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &rhs);
