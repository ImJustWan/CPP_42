#include "Serializer.hpp"
#include "Data.hpp"

Data::Data() : _type("Data"), _nb(8) {

	std::cout << _ITALIC "Data Constructor called" _END << std::endl;
	return;
}

Data::Data(uintptr_t raw) : _type("Data"), _nb(raw) {
	std::cout << _ITALIC "Data Constructor called" _END << std::endl;
	(void)raw;
	return;
}


Data::Data( Data const & src ) {

	std::cout << _ITALIC "Data Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

Data::~Data(void) {

	std::cout << _ITALIC "Data Destructor called" _END << std::endl;
	return;
}

const std::string&	Data::getType( void ) const {
	return this->_type;
}

const uintptr_t&	Data::getNb( void ) const {
	return this->_nb;
}

std::ostream &operator<<(std::ostream &o, Data const &i) {
	o << "\n🠮 Data Type is : " << i.getType() << std::endl;
	o << "🠮 Data Nb is : " << i.getNb() << std::endl;
	return o;
}