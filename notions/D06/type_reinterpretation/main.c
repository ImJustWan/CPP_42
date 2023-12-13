#include <stdio.h>

int main()
{
	float		a = 420.042f;		// Ref value

	void	*b = &a;				// Implicit reinterpretation cast
	void	*c = (void *)&a;		// Explicit reinterpretation cast

	void	*d = &a;				// Implicit promotion	-> OK
	int		*e = d;					// Implicit demotion	-> Hazardeous
	int		*f = (int *)d;			// Explicit demotion	-> OK, we're in charge
	float	*g = d;					// Implicit ??	-> 
	float	*h = (float *)f;		// Explicit ??	-> 

	printf("%p, %f\n", &a, a);

	printf("%p\n", b);
	printf("%p\n", c);

	printf("%p\n", d);
	printf("%p, %d\n", e, *e);
	printf("%p, %d\n", f, *f);
	printf("%p, %f\n", g, *g);
	printf("%p, %f\n", h, *h);
}
