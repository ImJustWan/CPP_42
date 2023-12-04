#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _name("Robot"), _target("Target"), _signed(false), _execGrade(45), _signGrade(72) {

	std::cout << _DARKGREY _ITALIC "Default RobotomyRequestForm Constructor called." << std::endl;
	std::cout << "Default name is : " << this->getName();
	std::cout << ", Exec Grade is " << this->getExecGrade();
	std::cout << ", Sign Grade is " << this->getSignGrade() << _END << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):  _name("Robot"), _target(target), _signed(false), _execGrade(45), _signGrade(72) {
	
	std::cout << _DARKGREY _ITALIC "RobotomyRequestForm Parametric Constructor called." << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) {

	std::cout << _DARKGREY _ITALIC "Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {

    std::cout << _DARKGREY _ITALIC "RobotomyRequestForm Destructor called (" << getName() << ")" _END << std::endl;
    return;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & n ) {
	
	std::cout << _DARKGREY _ITALIC "RobotomyRequestForm Copy Assignement operator called" _END << std::endl;
	this->_signed = n._signed;
	this->_execGrade = n._execGrade;
	this->_signGrade = n._signGrade;
	return *this;

}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i) {
	o << "\n🠮 RobotomyRequestForm Name : "<< i.getName() <<  ", Exec grade : " << i.getExecGrade() << ", Sign grade : " << i.getSignGrade() << std::endl;
	return o;
}

const std::string	&RobotomyRequestForm::getName(void) const {
	return this->_name;
}

const std::string	&RobotomyRequestForm::getTarget(void) const {
	return this->_target;
}

const int	&RobotomyRequestForm::getExecGrade(void) const {
	return this->_execGrade;
}

const int	&RobotomyRequestForm::getSignGrade(void) const {
	return this->_signGrade;
}

void	RobotomyRequestForm::robotomization() {
	
    std::cout << _YELLOW "🫨  *drilling noises* 🫨\n" _END <<std::endl;
	std::srand(time(NULL)); 
	if ((std::rand()) % 2 == 0)
		std::cout << _AQUAMARINE << this->getTarget() << " has been successfully robotomized └[∵┌]└[ ∵ ]┘[┐∵]┘ " _END << std::endl;
	else
		throw RobotFailed();

}
