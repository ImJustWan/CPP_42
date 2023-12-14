#pragma once

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <stdint.h>

struct Data {	

	Data( void );
	Data(uintptr_t raw);
	Data(Data const & src);
	~Data( void );
	const std::string&	getType( void ) const;
	const uintptr_t&	getNb( void ) const;

	std::string			_type;
	uintptr_t			_nb;

};

std::ostream & operator<<(std::ostream &o, Data const &rhs);
