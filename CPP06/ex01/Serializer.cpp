#include "Serializer.hpp"

Serializer::Serializer( ) {

	std::cout << _ITALIC "Serializer Copy Constructor called" _END << std::endl;
	return;
}

Serializer::~Serializer(void) {

	std::cout << _ITALIC "Serializer Destructor called" _END << std::endl;
	return;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
