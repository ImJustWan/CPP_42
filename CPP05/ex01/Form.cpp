#include "Form.hpp"

Form::Form() : _name("Betises"), _signed(false), _execGrade(75), _signGrade(75){

	std::cout << _DARKGREY _ITALIC "Default Form Constructor called\n";
	std::cout << "Default name is Betises, and they start with the lowest grade of 150" _END << std::endl;
	return;
}

Form::Form(std::string name, int exec, int sign) : _name(name), _signed(false) {
	
	if (exec < 1 || sign < 1)
		throw GradeTooHighException();
	else if (exec > 150 || sign > 150)
		throw GradeTooLowException();
	std::cout << _DARKGREY _ITALIC "Form Parametric Constructor called." << std::endl;
	this->_execGrade = exec;
	this->_signGrade = sign;
	std::cout << this->getName() << " has been created : ";
	std::cout << "Exec Grade is " << this->getExecGrade();
	std::cout << ", Sign Grade is " << this->getSignGrade() << _END << std::endl;
	return;
}

Form::Form( Form const & src ) : _name("Other" + src._name), _signed(false), _execGrade(src._execGrade), _signGrade(src._signGrade) {

	std::cout << _DARKGREY _ITALIC "Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

Form::~Form(void) {

	std::cout << _DARKGREY _ITALIC "Form Destructor called (" << getName() << ")" _END << std::endl;
	return;
}

Form & Form::operator=( Form const & n ) {
	
	std::cout << _DARKGREY _ITALIC "Form Copy Assignement operator called" _END << std::endl;
	this->_signed = n._signed;
	this->_execGrade = n._execGrade;
	this->_signGrade = n._signGrade;
	return *this;

}

std::ostream &operator<<(std::ostream &o, Form const &i) {
	o << "\n🠮 Form Name : "<< i.getName() <<  ", Exec grade : " << i.getExecGrade() << ", Sign grade : " << i.getSignGrade() << std::endl;
	return o;
}

void	Form::setSigned(bool tf) {
	this->_signed = tf;
}

const std::string	&Form::getName(void) const {
	return this->_name;
}

const bool	&Form::getSigned(void) const {
	return this->_signed;
}

const int	&Form::getExecGrade(void) const {
	return this->_execGrade;
}

const int	&Form::getSignGrade(void) const {
	return this->_signGrade;
}

/// @brief Increment the grade of the Exec Grade for the Form
/// @throw GradeTooHighException: can't be incremented
void	Form::incrementExecGrade(void) {
	
	if (this->_execGrade == 1)
		throw GradeTooHighException();
	this->_execGrade--;
	std::cout << _EMMERALD "Exec Grade for the Form" << this->getName() << " has been increased to rank ";
	std::cout << this->getExecGrade() << _END << std::endl;
}

/// @brief Increment the grade of the Exec Grade for the Form
/// @throw GradeTooHighException: can't be incremented
void	Form::incrementSignGrade(void) {
	
	if (this->_signGrade == 1)
		throw GradeTooHighException();
	this->_signGrade--;
	std::cout << _EMMERALD "Sign Grade for the Form" << this->getName() << " has been increased to rank ";
	std::cout << this->getSignGrade() << _END << std::endl;
}

/// @brief Decrement the grade of the Exec Grade for the Form
/// @throw GradeTooHighException: can't be decremented
void	Form::decrementExecGrade(void) {
	
	if (this->_execGrade == 150)
		throw GradeTooLowException();
	this->_execGrade++;
	std::cout << _EMMERALD "Exec Grade for the Form" << this->getName() << " has been decreased to rank ";
	std::cout << this->getExecGrade() << _END << std::endl;
}

/// @brief Decrement the grade of the Exec Grade for the Form
/// @throw GradeTooHighException: can't be decremented
void	Form::decrementSignGrade(void) {
	
	if (this->_signGrade == 150)
		throw GradeTooLowException();
	this->_signGrade++;
	std::cout << _EMMERALD "Sign Grade for the Form" << this->getName() << " has been decreased to rank ";
	std::cout << this->getSignGrade() << _END << std::endl;
}

void	Form::beSigned(Bureaucrat const &person) {
	if (&person == static_cast<Bureaucrat*>(0)) {
		std::cout << _MAROON _BOLD "\nI need a real Bureaucrat to sign this.\n" _END << std::endl;
		return;
	}
	if (person.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	this->_signed = true;
	std::cout << _AQUAMARINE _BOLD "\n" << this->getName() << " has officially been signed 🍾\n" _END << std::endl;
}
