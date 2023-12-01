#include "Form.hpp"

Form::Form() : _name("Grint"), _grade(150) {

	std::cout << _ITALIC "Default Form Constructor called :";
	std::cout << " default name is Grint, and they start with the lowest grade of 150" _END << std::endl;
	return;
}

Form::Form(std::string name, int grade) : _name(name), _grade(grade) {
	
	std::cout << _ITALIC "Form String Parametric Constructor called (" << name << ")" _END << std::endl;
	return;
}

Form::Form( Form const & src ) : _name(src._name), _grade(src._grade) {

	std::cout << _ITALIC "Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

Form::~Form(void) {

    std::cout << _ITALIC "Form Destructor called (" << getName() << ")" _END << std::endl;
    return;
}

Form & Form::operator=( Form const & n ) {
	
	std::cout << _ITALIC "Form Copy Assignement operator called" _END << std::endl;
	this->_grade = n._grade;
	return *this;

}

std::ostream &operator<<(std::ostream &o, Form const &i) {
	o << i.getName() << ", Form grade " << i.getGrade();
	return o;
}

const std::string	&Form::getName(void) const {
	return this->_name;
}

const int	&Form::getGrade(void) const {
	return this->_grade;
}

void	Form::incrementGrade(void) {
	
	try
	{
		if (this->_grade == 1)
			throw GradeTooHighException();
		else
		{
			this->_grade--;
			std::cout << _EMMERALD << this->getName() << " has been promoted to rank ";
			std::cout << this->getGrade() << _END << std::endl;
		}
	}
	catch(const GradeTooHighException& e) {
		std::cout << _FOREST_GREEN "✨ "<< this->getName() << " has already achieved the highest rank (シ_ _)シ" _END << std::endl;
	}
}

void	Form::decrementGrade(void) {

	try
	{
		if (this->_grade == 150)
			throw GradeTooLowException();
		else
		{
			this->_grade++;
			std::cout << _SALMON << this->getName() << " has been demoted to rank ";
			std::cout << this->getGrade() << _END << std::endl;
		}
	}
	catch(const GradeTooLowException& e) {
		std::cout << _RED "❌ " << this->getName() << " is already at the bottom of the ladder ( ´･･)ﾉ(._.`)" _END << std::endl;
	}
}
