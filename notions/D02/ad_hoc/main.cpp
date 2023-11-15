#include "Sample.class.hpp"

int main()
{
	Sample instance;
	
	instance.bar('t');
	instance.bar(42);
	instance.bar(3.14f);
	instance.bar( instance );
	return (0);
}