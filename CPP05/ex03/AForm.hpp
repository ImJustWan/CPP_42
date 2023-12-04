#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "colors.hpp"
#include "Bureaucrat.hpp"

# define _TREE "\t\t\t _-_\n    /~~   ~~\\\n\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~   \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n"

class Bureaucrat;

class AForm {

public:
	AForm();
	AForm(AForm const &);
	AForm(std::string name, int exec, int sign);
	AForm &operator=(AForm const &);
	virtual ~AForm();

	virtual const std::string	&getName() const;
	virtual const bool			&getSigned() const;
	virtual const int			&getExecGrade() const;
	virtual const int			&getSignGrade() const;
	virtual void				setSigned(bool tf);
	virtual void				incrementExecGrade();
	virtual void				decrementExecGrade();
	virtual void				incrementSignGrade();
	virtual void				decrementSignGrade();
	virtual void				beSigned(Bureaucrat const &person);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_BOLD _LIGHTGREY "I can't trust a rank that high !" _END);
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_BOLD _LIGHTGREY "Lower than rank 150, really ?!" _END);
			}
	};

protected:
	std::string const	_name;
	bool				_signed;
	int					_execGrade;
	int					_signGrade;

};

std::ostream & operator<<(std::ostream &o, AForm const &rhs);
