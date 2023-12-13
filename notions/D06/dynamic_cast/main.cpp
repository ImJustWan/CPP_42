#include <iostream>
#include <typeinfo>
#include <exception>

class Parent { public: virtual ~Parent(void){}};
class Child1: public Parent {};
class Child2: public Parent {};

int main()
{
	Child1		a;									// Ref value
	Parent		*b = &a;							// Implicit upcast -> OK

	// Explicit downcast -> 
	Child1		*c = dynamic_cast<Child1 *>(b);
	// Pointers can be NULL
	if (c == NULL)
		std::cout << "Conversion is NOT OK" << std::endl;
	else
		std::cout << "Conversion is OK" << std::endl;
	
	// Explicit downcast -> 
	// Ref can NOT be NULL -> throw exception
	try {
		Child2 &d = dynamic_cast<Child2 &>(*b);
		std::cout << "Conversion is OK" << std::endl;
	}
	catch (std::bad_cast &bc) {
		std::cout << "Conversion is NOT OK : " << bc.what() << std::endl;
		return 0;
	}
	return 0;
}