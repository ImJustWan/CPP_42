#include "Harl.hpp"
#include "colors.hpp"

typedef void (*COMPLAINS);

Harl::Harl(void) {

	// std::cout << "Constructor called" << std::endl;
	return;
}

Harl::~Harl(void) {

	// std::cout << "Destructor called" << std::endl;
	return;
}

void Harl::complain( std::string level ) {

	std::string complaint[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i;
	for (i = 0; i < 4; i++)
		if (level == complaint[i])
			break; 
	switch ( i )
	::
	return;
}


void Harl::debug( void ) {

	std::cout << _BOLD _FOREST_GREEN _BLINK "[DEBUG]" _END << std::endl;
	std::cout << _ITALIC _BOLD _UNDERLINE "HarlFilter:" _END << " ";
	std::cout << _ITALIC _GREY "I needed an objective frame of reference by which to judge the experience of your company. Somewhere between four and five blowsto the head, I place it.\n\n" _END << std::endl;
	return;
}

void Harl::info( void ) {

	std::cout << _BOLD _YELLOW _BLINK "[INFO]" _END << std::endl;
	std::cout << _ITALIC _BOLD _UNDERLINE "HarlFilter:" _END << " ";
	std::cout << _ITALIC _GREY "Like a fashionable dress, stupidity can be fetching in youth, but looks particularly bad on the aged. And unique as its properties may be, stupidity is frighteningly common. The sum total of stupid people is somewhere around the population of the planet. Plus one.\n\n" _END << std::endl;
	return;
}

void Harl::warning( void ) {

	std::cout << _BOLD _ORANGE _BLINK "[WARNING]" _END << std::endl;
	std::cout << _ITALIC _BOLD _UNDERLINE "HarlFilter:" _END << " ";
	std::cout << _ITALIC _GREY "Yes, yes. Aim for the sun. That way if you miss, at least your arrow will fall far away, and the person it kills will likely be someone you don't know.\n\n" _END << std::endl;
	return;
}

void Harl::error( void ) {

	std::cout << _BOLD _RED _BLINK "[ERROR]" _END<< std::endl;
	std::cout << _ITALIC _BOLD _UNDERLINE "HarlFilter:" _END << " ";
	std::cout << _ITALIC _GREY "Child, you’re inept enough to make the Hundred Idiots look brilliant.\n\n" _END << std::endl;
	return;
}

