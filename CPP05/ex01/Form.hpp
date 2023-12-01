#pragma once

#include <iostream>
#include <string>
#include "colors.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	std::string const	_name;
	bool				_signed;
	int					_execGrade;
	int					_signGrade;

public:
	Form();
	Form(Form const &);
	Form(std::string name, int exec, int sign);
	Form &operator=(Form const &);
	~Form();

	const std::string	&getName() const;
	const bool			&getSigned() const;
	const int			&getExecGrade() const;
	const int			&getSignGrade() const;
	void				setSigned(bool tf);
	void				incrementExecGrade();
	void				decrementExecGrade();
	void				incrementSignGrade();
	void				decrementSignGrade();
	void				beSigned(Bureaucrat const &person);

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

};

std::ostream & operator<<(std::ostream &o, Form const &rhs);
