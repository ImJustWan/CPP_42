#include "Contact.hpp"

std::string	Contact::getFirstName(void) const {

    return this->_FirstName;
}

void	Contact::setFirstName(std::string FirstName) {

    this->_FirstName = FirstName;
    return;
}

std::string	Contact::getLastName(void) const {

    return this->_LastName;
}

void	Contact::setLastName(std::string LastName) {

    this->_LastName = LastName;
    return;
}

std::string	Contact::getNickName(void) const {

    return this->_NickName;
}

void	Contact::setNickName(std::string NickName) {

    this->_NickName = NickName;
    return;
}

std::string	Contact::getPhoneNumber(void) const {

    return this->_PhoneNumber;
}

void	Contact::setPhoneNumber(std::string PhoneNumber) {

	std::string validNumbers = " 0123456789+-()";

    // this->_PhoneNumber = PhoneNumber;

    while ( PhoneNumber.size() == 0 )
	{
		std::getline( std::cin, PhoneNumber );
		if (PhoneNumber.find_first_not_of(validNumbers) != std::string::npos)
		{
			// std::cout << validNumbers.find_first_not_of(PhoneNumber) << std::endl;
            PhoneNumber = "";
			std::cout << "Wrong PhoneNumber format, try again: " << std::endl;
		}
		else
			this->_PhoneNumber = PhoneNumber;
	}
    return;
}

std::string	Contact::getDarkestSecret(void) const {

    return this->_DarkestSecret;
}

void	Contact::setDarkestSecret(std::string DarkestSecret) {

    this->_DarkestSecret = DarkestSecret;
    return;
}
