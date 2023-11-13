#include "PhoneBook.hpp"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <iomanip>

PhoneBook::PhoneBook( void ) {

	return;	
}

PhoneBook::~PhoneBook( void ) {

	return;	
}

void	PhoneBook::DisplayContact( Contact &ZeContact ) const {

	std::cout << "FirstName is: " << ZeContact.getFirstName() << std::endl;
	std::cout << "LastName is: " << ZeContact.getLastName() << std::endl;
	std::cout << "NickName is: " << ZeContact.getNickName() << std::endl;
	std::cout << "PhoneNumber is: " << ZeContact.getPhoneNumber() << std::endl;
	std::cout << "DarkestSecret is: " << ZeContact.getDarkestSecret() << std::string(2, '\n') << std::endl;
	return;
}

std::string	listenInput(std::string str)
{
	while (str.size() == 0)
		std::getline( std::cin, str);
	return (str);
}

void	PhoneBook::AddContact( Contact &NewContact ) {

	std::string validNumbers = " 0123456789+-()";

	std::cout << "\nYou're adding a new contact !\n"  << std::endl;

	std::cout << "Input FirstName: ";
	NewContact.setFirstName(listenInput(""));
	std::cout << "Input LastName: ";
	NewContact.setLastName(listenInput(""));
	std::cout << "Input NickName: ";
	NewContact.setNickName(listenInput(""));
	std::cout << "Input PhoneNumber: ";
	NewContact.setPhoneNumber("");
	std::cout << "Input DarkestSecret: ";
	NewContact.setDarkestSecret(listenInput(""));	
	
	std::cout << "NewContact added ~\n" << std::endl;

	return ;
}

void	_printString( std::string str )
{
	if ( str.size() <= 10 )
		std::cout << std::setw( 10 ) << str;
	else
	{	for ( int j = 0; j < 9; j++ )
			std::cout << str[j];
		std::cout << ".";
	}
	return;
}

int	PhoneBook:: DisplayRepertory( PhoneBook &repertory ) const {

	int	index = 0;

	std::cout << "\nHere's your current repertory :]\n"  << std::endl;

	for ( int i = 0; i < 8; i++ )
	{
		std::cout << std::setw( 10 ) << i + 1;
		std::cout << "|";
		_printString( repertory.Contacts[i].getFirstName() );
		std::cout << "|";
		_printString( repertory.Contacts[i].getLastName() );
		std::cout << "|";
		_printString( repertory.Contacts[i].getNickName() );
		std::cout << std::endl;
	}

	std::cout << "\nPick an index ~\n" << std::endl;
	std::string str;
	getline( std::cin, str );
	if ( !str.size() || str.size() != 1 || !isdigit(str[0]) )
		return (std::cout << "\nInvalid index  back to the repertory (''-_-)ゞ\n" << std::endl, 1);
	
	index = atoi( str.c_str() );
	std::cout << "\nIndex is : " << index << std::endl;
	if ( index >= 1 && index <= 8 )
		return (DisplayContact( repertory.Contacts[index - 1] ), 0);
	return (std::cout << "WTF you're doing bro ? Try again (╬ Ò ‸ Ó)ゞ\n" << std::endl, 0);
}

