#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _name("Pardon"), _signed(false), _execGrade(5), _signGrade(25) {

	std::cout << _DARKGREY _ITALIC "Default PresidentialPardonForm Constructor called." << std::endl;
	std::cout << "Default name is : " << this->getName();
	std::cout << ", Exec Grade is " << this->getExecGrade();
	std::cout << ", Sign Grade is " << this->getSignGrade() << _END << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name): _name(name), _signed(false), _execGrade(5), _signGrade(25) {
	
	std::cout << _DARKGREY _ITALIC "PresidentialPardonForm Parametric Constructor called." << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : AForm("Other" + src._name, 5, 25) {

	std::cout << _DARKGREY _ITALIC "Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {

    std::cout << _DARKGREY _ITALIC "PresidentialPardonForm Destructor called (" << getName() << ")" _END << std::endl;
    return;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & n ) {
	
	std::cout << _DARKGREY _ITALIC "PresidentialPardonForm Copy Assignement operator called" _END << std::endl;
	this->_signed = n._signed;
	this->_execGrade = n._execGrade;
	this->_signGrade = n._signGrade;
	return *this;

}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i) {
	o << "\n🠮 PresidentialPardonForm Name : "<< i.getName() <<  ", Exec grade : " << i.getExecGrade() << ", Sign grade : " << i.getSignGrade() << std::endl;
	return o;
}

const std::string	&PresidentialPardonForm::getName(void) const {
	return this->_name;
}

const int	&PresidentialPardonForm::getExecGrade(void) const {
	return this->_execGrade;
}

const int	&PresidentialPardonForm::getSignGrade(void) const {
	return this->_signGrade;
}


void	PresidentialPardonForm::amnesty(std::string target) {
	
    std::cout << _AQUAMARINE << target << " has been pardonned, FREEDOM ৻(  •̀ ᗜ •́  ৻) " _END << std::endl;
}
