#pragma once

#include <string>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <iomanip>

class Contact {

public :
	Contact(void);
	~Contact(void);

	std::string	getFirstName(void) const;
	void		setFirstName(std::string FirstName);
	std::string	getLastName(void) const;
	void		setLastName(std::string LastName);
	std::string	getNickName(void) const;
	void		setNickName(std::string NickName);
	std::string	getPhoneNumber(void) const;
	void		setPhoneNumber(std::string PhoneNumber);
	std::string	getDarkestSecret(void) const;
	void		setDarkestSecret(std::string DarkestSecret);

private:
	std::string	_FirstName;
	std::string	_LastName;
	std::string	_NickName;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;
};
