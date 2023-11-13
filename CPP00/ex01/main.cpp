#include <iostream>
#include <string.h>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"


int main() {

	PhoneBook		repertory;
	int 			i = 0;
	std::string		str;

	while ( 1 )
	{
		std::cout << "You can either ADD, SEARCH or EXIT :)\n" << std::endl;
		while ( str.size() == 0 )
		{
			if (std::cin.eof())
				return (std::cout << "\nIf you take it that way, bye ゞ(╬ Ò.Ó)ゞ\n"  << std::endl, 0);
			std::getline( std::cin, str );
		}
		if ( str == "ADD")
		{
			if ( i < 8 )
				repertory.AddContact( repertory.Contacts[i] );
			else
				repertory.AddContact( repertory.Contacts[0] );
			i++;
		}
		else if ( str == "SEARCH" )
			repertory.DisplayRepertory( repertory );
		if ( str == "EXIT" )
			return 0; 
		str = "";
	}
	return 0;
}