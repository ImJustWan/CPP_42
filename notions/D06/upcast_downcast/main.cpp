#include <iostream>

class Parent {};
class Child1: public Parent {};
class Child2: public Parent {};

int main()
{
	Child1	a;						// Ref value

	Parent	*b = &a;				// Implicit 'reinterpretation' cast
	Parent	*c = (Parent *)&a;		// Explicit 'reinterpretation' cast

	Parent	*d = &a;				// Implicit upcast -> OK
	// Child1	*e = d;					// Implicit downcast ->  NOPE
	Child2	*f = (Child2 *)d;		// Implicit downcast ->  OK, but really ? Child1 =/= Child2
	return 0;
}