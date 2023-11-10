#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <string.h>

class Contact {

public :

	Contact(void);
	~Contact(void);

private:

	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	PhoneNumber;
	std::string	DarkestSecret;
};

#endif