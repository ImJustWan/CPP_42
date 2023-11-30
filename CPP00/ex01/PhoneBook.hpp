#pragma once

#include "Contact.hpp"

class PhoneBook {

public :

	PhoneBook( void );
	~PhoneBook( void );

	Contact Contacts[8];

	void		AddContact( Contact &NewContact );
	int	    	DisplayRepertory( PhoneBook &repertory ) const;
	void    	DisplayContact( Contact &ZeContact ) const;
};
