void	dump_32bits_integer(int const n);
void	dump_64bits_double(double const z);



int main()
{
	int		a = 42;				// Ref value

	double	b = a;				// Implicit conversion cast
	double	c = (double)a;		// Explicit conversion cast

	double	d = a;				// Implicit promotion	-> OK
	int		e = d;				// Implicit demotion	-> Hazardeous
	int		f = (int)d;			// Explicit demotion	-> OK, we're in charge

	dump_32bits_integer(a);

	dump_64bits_double(b);
	dump_64bits_double(c);

	dump_64bits_double(d);
	dump_32bits_integer(e);
	dump_32bits_integer(f);
}
