#include <stdio.h>

int main()
{
	int			a = 42;					// Ref value

	int const	*b = &a;				// Implicit type qualifier cast
	int const	*c = (int const *)&a;	// Explicit type qualifier cast

	int const	*d = &a;				// Implicit promotion	-> OK
	// int			*e = d;				// Implicit demotion	-> NOT POSSIBLE
	int			*f = (int *)d;			// Explicit demotion	-> OK, we're in charge

	printf("%p, %d\n", &a, a);

	printf("%p\n", b);
	printf("%p\n", c);

	printf("%p\n", d);
	printf("%p\n", f);

}
