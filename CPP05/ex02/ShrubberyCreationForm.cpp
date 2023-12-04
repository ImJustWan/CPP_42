#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _name("Forest"), _signed(false), _execGrade(137), _signGrade(145) {

	std::cout << _DARKGREY _ITALIC "Default ShrubberyCreationForm Constructor called." << std::endl;
	std::cout << "Default name is : " << this->getName();
	std::cout << ", Exec Grade is " << this->getExecGrade();
	std::cout << ", Sign Grade is " << this->getSignGrade() << _END << std::endl;
	return;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string name): _name(name) {
	
	std::cout << _DARKGREY _ITALIC "ShrubberyCreationForm Parametric Constructor called." << std::endl;
	return;
}


ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : AForm("Other" + src._name, 137, 145) {

	std::cout << _DARKGREY _ITALIC "Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

    std::cout << _DARKGREY _ITALIC "ShrubberyCreationForm Destructor called (" << getName() << ")" _END << std::endl;
    return;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & n ) {
	
	std::cout << _DARKGREY _ITALIC "ShrubberyCreationForm Copy Assignement operator called" _END << std::endl;
	this->_signed = n._signed;
	this->_execGrade = n._execGrade;
	this->_signGrade = n._signGrade;
	return *this;

}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i) {
	o << "\n🠮 ShrubberyCreationForm Name : "<< i.getName() <<  ", Exec grade : " << i.getExecGrade() << ", Sign grade : " << i.getSignGrade() << std::endl;
	return o;
}

const std::string	&ShrubberyCreationForm::getName(void) const {
	return this->_name;
}

const int	&ShrubberyCreationForm::getExecGrade(void) const {
	return this->_execGrade;
}

const int	&ShrubberyCreationForm::getSignGrade(void) const {
	return this->_signGrade;
}

void	ShrubberyCreationForm::createShrubbery(std::string target) {
	
	std::string	outfileName = target + "_shubbery";
	std::ofstream ofs(outfileName.c_str());

	if (!ofs.is_open())
		throw OutfileOpening();
	ofs << _TREE << "\n\n" << _TREE << "\n\n" << _TREE;
	std::cout << _AQUAMARINE "Check your <TargetFileName> ! (づ •. •)づ\n" _END << std::endl;
}
