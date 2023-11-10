#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {

public :

	PhoneBook( void );
	~PhoneBook( void );

	Contact Contacts[8];

	void		AddContact( Contact &NewContact );
	void    	DisplayRepertory( PhoneBook &repertory ) const;
	void    	DisplayContact( Contact &ZeContact ) const;
	void		clearFirst( Contact &Contact );
};

#endif