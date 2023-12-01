#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _name("Betises"), _signed(false), _execGrade(137), _signGrade(145) {

	std::cout << _DARKGREY _ITALIC "Default RobotomyRequestForm Constructor called." << std::endl;
	std::cout << "Default name is : " << this->getName();
	std::cout << ", Exec Grade is " << this->getExecGrade();
	std::cout << ", Sign Grade is " << this->getSignGrade() << _END << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name): _name(name) {
	
	std::cout << _DARKGREY _ITALIC "RobotomyRequestForm Parametric Constructor called." << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : AForm("Other" + src._name, 137, 145) {

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

void	RobotomyRequestForm::robotomization(std::string target) {
	
    std::cout << _YELLOW "🫨  *drilling noises* 🫨\n" _END <<std::endl;
	std::srand(time(NULL)); 
	if ((std::rand()) % 2 == 0)
		std::cout << _AQUAMARINE << target << " has been successfully robotomized └[∵┌]└[ ∵ ]┘[┐∵]┘ " _END << std::endl;
	else
		throw RobotFailed();

}
