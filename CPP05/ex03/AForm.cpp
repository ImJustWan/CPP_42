#include "AForm.hpp"

AForm::AForm() : _name("Betises"), _signed(false), _execGrade(75), _signGrade(75) {

	// std::cout << _DARKGREY _ITALIC "Default AForm Constructor called\n";
	return;
}

AForm::AForm(std::string name, int exec, int sign) : _name(name), _signed(false) {
	
	if (exec < 1 || sign < 1)
		throw GradeTooHighException();
	else if (exec > 150 || sign > 150)
		throw GradeTooLowException();
	// std::cout << _DARKGREY _ITALIC "AForm Parametric Constructor called." << std::endl;
	this->_execGrade = exec;
	this->_signGrade = sign;
	std::cout << this->getName() << " has been created : ";
	std::cout << "Exec Grade is " << this->getExecGrade();
	std::cout << ", Sign Grade is " << this->getSignGrade() << _END << std::endl;
	return;
}

AForm::AForm( AForm const & src ) : _name("Other" + src._name), _signed(false), _execGrade(src._execGrade), _signGrade(src._signGrade) {

	std::cout << _DARKGREY _ITALIC "Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

AForm::~AForm(void) {

	// std::cout << _DARKGREY _ITALIC "AForm Destructor called (" << getName() << ")" _END << std::endl;
	return;
}

AForm & AForm::operator=( AForm const & n ) {
	
	std::cout << _DARKGREY _ITALIC "AForm Copy Assignement operator called" _END << std::endl;
	this->_signed = n._signed;
	this->_execGrade = n._execGrade;
	this->_signGrade = n._signGrade;
	return *this;

}

std::ostream &operator<<(std::ostream &o, AForm const &i) {
	o << "\n🠮 AForm Name : "<< i.getName() <<  ", Exec grade : " << i.getExecGrade() << ", Sign grade : " << i.getSignGrade() << std::endl;
	return o;
}

void	AForm::setSigned(bool tf) {
	this->_signed = tf;
}

const std::string	&AForm::getName(void) const {
	return this->_name;
}

const bool	&AForm::getSigned(void) const {
	return this->_signed;
}

const int	&AForm::getExecGrade(void) const {
	return this->_execGrade;
}

const int	&AForm::getSignGrade(void) const {
	return this->_signGrade;
}

/// @brief Increment the grade of the Exec Grade for the AForm
/// @throw GradeTooHighException: can't be incremented
void	AForm::incrementExecGrade(void) {
	
	if (this->_execGrade == 1)
		throw GradeTooHighException();
	this->_execGrade--;
	std::cout << _EMMERALD "Exec Grade for the AForm" << this->getName() << " has been increased to rank ";
	std::cout << this->getExecGrade() << _END << std::endl;
}

/// @brief Increment the grade of the Exec Grade for the AForm
/// @throw GradeTooHighException: can't be incremented
void	AForm::incrementSignGrade(void) {
	
	if (this->_signGrade == 1)
		throw GradeTooHighException();
	this->_signGrade--;
	std::cout << _EMMERALD "Sign Grade for the AForm" << this->getName() << " has been increased to rank ";
	std::cout << this->getSignGrade() << _END << std::endl;
}

/// @brief Decrement the grade of the Exec Grade for the AForm
/// @throw GradeTooHighException: can't be decremented
void	AForm::decrementExecGrade(void) {
	
	if (this->_execGrade == 150)
		throw GradeTooLowException();
	this->_execGrade++;
	std::cout << _EMMERALD "Exec Grade for the AForm" << this->getName() << " has been decreased to rank ";
	std::cout << this->getExecGrade() << _END << std::endl;
}

/// @brief Decrement the grade of the Exec Grade for the AForm
/// @throw GradeTooHighException: can't be decremented
void	AForm::decrementSignGrade(void) {
	
	if (this->_signGrade == 150)
		throw GradeTooLowException();
	this->_signGrade++;
	std::cout << _EMMERALD "Sign Grade for the AForm" << this->getName() << " has been decreased to rank ";
	std::cout << this->getSignGrade() << _END << std::endl;
}

void	AForm::beSigned(Bureaucrat const &person) {
	if (&person == static_cast<Bureaucrat*>(0)) {
		std::cout << _MAROON _BOLD "\nI need a real Bureaucrat to sign this.\n" _END << std::endl;
		return;
	}
	if (person.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	this->_signed = true;
	std::cout << _AQUAMARINE _BOLD "\n" << this->getName() << " has officially been signed 🍾\n" _END << std::endl;
}

void	AForm::execute(Bureaucrat const & executor) {
	if (&executor == static_cast<Bureaucrat*>(0)) {
		std::cout << _MAROON _BOLD "\nI need a real Bureaucrat.\n" _END << std::endl;
		return;
	}
	else if (this->getSigned() == false) {
		std::cout << _MAROON _BOLD "\nForm isn't signed, sorry.\n" _END << std::endl;
		return;
	}
	else if (executor.getGrade() > this->getExecGrade()) {
		std::cout << _MAROON _BOLD "\nExecutor's grade is too low.\n" _END << std::endl;
		return;
	}
	// std::cout << executor.getName() << "is executing." << std::endl;
	this->executeAction(executor);
}
