#include "Base.hpp"

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base::~Base(void) {

	std::cout << _GREY _ITALIC "Base Destructor called" _END << std::endl;
	return;
}

Base *Base::generate(void){

	// count is used as a seed to get randomized value
	static unsigned int count = 0;
	std::srand(static_cast<unsigned>(std::time(NULL) + count ++));

	int randm = std::rand() % 3;
	switch (randm) 
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return(NULL);
}

void	Base::identify(Base* p){

	A	*tmpA = dynamic_cast<A *>(p);
	B	*tmpB = dynamic_cast<B *>(p);
	C	*tmpC = dynamic_cast<C *>(p);

	// Pointers can be NULL
	if (tmpA)
		std::cout << _ITALIC _GREY "(via pointer)\t" _END " Type is : A" << std::endl;
	else if (tmpB)
		std::cout << _ITALIC _GREY "(via pointer)\t" _END " Type is : B" << std::endl;
	else if (tmpC)
		std::cout << _ITALIC _GREY "(via pointer)\t" _END " Type is : C" << std::endl;
	return;
}

void	Base::identify(Base& p){

	// ref can't be NULL
	// dynamic_cast will throw an exception if failure
	try {
		A	&tmpA = dynamic_cast<A &>(p);
		std::cout << _ITALIC _GREY "(via reference)\t" _END " Type is : A" << std::endl;
		(void)tmpA;
	}
	catch (std::exception &e) {
	}
	try {
		B	&tmpB = dynamic_cast<B &>(p);
		std::cout << _ITALIC _GREY "(via reference)\t" _END " Type is : B" << std::endl;
		(void)tmpB;
	}
	catch (std::exception &e) {
	}
	try {
		C	&tmpC = dynamic_cast<C &>(p);
		std::cout << _ITALIC _GREY "(via reference)\t" _END " Type is : C" << std::endl;
		(void)tmpC;
	}
	catch (std::exception &e) {
	}
	return;
}

