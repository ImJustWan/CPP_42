#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Grint"), _grade(150) {

	std::cout << _DARKGREY _ITALIC "Default Bureaucrat Constructor called\n";
	std::cout << "Default name is Grint, and they start with the lowest grade of 150" _END << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	
	// std::cout << _ITALIC "Bureaucrat Parametric Constructor called (" << name << ")" _END << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();

	this->_grade = grade;
	std::cout << _DARKGREY _ITALIC << this->getName() << " has entered the game at rank ";
	std::cout << this->getGrade() << _END << std::endl;
	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name(src._name), _grade(src._grade) {

	std::cout << _DARKGREY _ITALIC "Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat(void) {

    std::cout << _DARKGREY _ITALIC "Bureaucrat Destructor called (" << getName() << ")" _END << std::endl;
    return;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & n ) {
	
	std::cout << _DARKGREY _ITALIC "Bureaucrat Copy Assignement operator called" _END << std::endl;
	this->_grade = n._grade;
	return *this;

}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i) {
	o << "\n🠮 "<< i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return o;
}

const std::string	&Bureaucrat::getName(void) const {
	return this->_name;
}

const int	&Bureaucrat::getGrade(void) const {
	return this->_grade;
}

/// @brief Increment the grade of the Bureaucrat
/// @throw GradeTooHighException: can't be incremented
void	Bureaucrat::incrementGrade(void) {
	
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
	std::cout << _EMMERALD << this->getName() << " has been promoted to rank ";
	std::cout << this->getGrade() << _END << std::endl;
}

/// @brief Decrement the grade of the Bureaucrat
/// @throw GradeTooLowException: can't be decremented
void	Bureaucrat::decrementGrade(void) {

	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
	std::cout << _SALMON << this->getName() << " has been demoted to rank ";
	std::cout << this->getGrade() << _END << std::endl;
}
