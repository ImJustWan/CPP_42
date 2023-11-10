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


void	PhoneBook::clearFirst( Contact &First ) {

	First.FirstName = "";
	First.LastName = "";
	First.NickName = "";
	First.PhoneNumber = "";
	First.DarkestSecret = "";
	return;
}


void	PhoneBook::DisplayContact( Contact &ZeContact ) const {


	std::cout << "FirstName is :" << ZeContact.FirstName << std::endl;
	std::cout << "LastName is :" << ZeContact.LastName << std::endl;
	std::cout << "NickName is :" << ZeContact.NickName << std::endl;
	std::cout << "PhoneNumber is :" << ZeContact.PhoneNumber << std::endl;
	std::cout << "DarkestSecret is :" << ZeContact.DarkestSecret << std::string(2, '\n') << std::endl;
	return;
}


void	PhoneBook::AddContact( Contact &NewContact ) {

	std::string validNumbers = " 0123456789+-()";
	std::string str = "tmp";

	std::cout << "\nYou're adding a new contact !\n"  << std::endl;

	std::cout << "Input FirstName: ";
	while ( NewContact.FirstName.size() == 0 )
		std::getline( std::cin, NewContact.FirstName );
	std::cout << "Input LastName: ";
	while ( NewContact.LastName.size() == 0 )
		std::getline( std::cin, NewContact.LastName );
	std::cout << "Input NickName: ";
	while ( NewContact.NickName.size() == 0 )
		std::getline( std::cin, NewContact.NickName );
	std::cout << "Input PhoneNumber: ";
	while ( NewContact.PhoneNumber.size() == 0 )
	{
		std::getline( std::cin, str );
		if (str.find_first_not_of(validNumbers) != std::string::npos)
		{
			std::cout << validNumbers.find_first_not_of(str) << std::endl;
			std::cout << "Wrong PhoneNumber format, try again: " << std::endl;
		}
		else
			NewContact.PhoneNumber = str;
	}
	std::cout << "Input DarkestSecret: ";
	while ( NewContact.DarkestSecret.size() == 0 )
		std::getline( std::cin, NewContact.DarkestSecret );	
	
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

void	PhoneBook:: DisplayRepertory( PhoneBook &repertory ) const {

	int	index = 0;

	std::cout << "\nHere's your current repertory :]\n"  << std::endl;

	for ( int i = 0; i < 8; i++ )
	{
		std::cout << std::setw( 10 ) << i + 1;
		std::cout << "|";
		_printString( repertory.Contacts[i].FirstName );
		std::cout << "|";
		_printString( repertory.Contacts[i].LastName );
		std::cout << "|";
		_printString( repertory.Contacts[i].NickName );
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Pick an index ~\n" << std::endl;

	std::string str;
	getline( std::cin, str );
	if ( !str.size() || str.size() != 1 || !isdigit(str[0]) )
	{
		std::cout << "\nInvalid index, back to the repertory\n" << std::endl;
		return ;
	}
	index = atoi( str.c_str() );
	std::cout << "Index is : " << index << std::endl;
	if ( index >= 1 && index <= 8 )
	{
		std::cout << "Index is : " << index << std::endl;
		DisplayContact( repertory.Contacts[index - 1] );
	}
	else
		std::cout << "WTF you're doing bro ? Try again\n" << std::endl;
	return;
}

