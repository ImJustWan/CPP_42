#pragma once

#include "colors.hpp"

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <stdint.h>
#include <ctime> 

class Base {	

private:

	// Base();

public:

	virtual ~Base();

	static Base	*generate(void);
	static void	identify(Base* p);
	static void	identify(Base& p);

};
