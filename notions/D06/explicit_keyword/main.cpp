#include <iostream>

class A{};

class B{};

class C{

	public:
				C(A const & _) {return ;}
	explicit	C(B const & _) {return ;}

};

void	f( C const &_){
	return;
}

int main()
{
	f( A() );			// Implicit conversion -> OK
	// f( B() );		// Implicit conversion -> NOT OK, constructor is explicit
	f( C(B()) );		// Explicit construction -> OK, instance is created from B, f can be called

	return 0;
}