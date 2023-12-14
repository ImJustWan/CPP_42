#pragma once

#include "colors.hpp"
#include "Data.hpp"

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <stdint.h>

class Serializer {	

private:

	Serializer();
	~Serializer();


public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

};

