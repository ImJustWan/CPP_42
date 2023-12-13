#include <iostream>

class Parent {};
class Child1: public Parent {};
class Child2: public Parent {};

class Unrelated {};

int main()
{
	Child1		a;									// Ref value

	Parent		*b = &a;							// Implicit upcast -> OK
	// Child1		*c = b;							// Implicit downcast ->  NOPE
	Child2		*d = static_cast<Child2 *>(b);		// Explicit downcast ->  OK, we're in charge

	// Unrelated	*e = static_cast<Unrelated *>(&a);	// Explicit conversion -> NOPE

	return 0;
}