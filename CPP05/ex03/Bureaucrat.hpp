#pragma once

#include <iostream>
#include <string>
#include "colors.hpp"
#include "AForm.hpp"

class AForm;

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
	void				signForm(AForm &randomForm);
	void				executeForm(AForm const & form);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED _BOLD "❌ Grade is too high, no can do\n" _END);
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED _BOLD "❌ Grade is too low, no can do\n" _END);
			}
	};

};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &rhs);
