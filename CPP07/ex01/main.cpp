#include "iter.hpp"

void	to_lower(int &woop)
{
	woop = tolower(woop);
}
template < typename T >
void	opposite(T woop)
{
	woop *= -1;
}

int main()
{
	int		a[] = {'A', 'B', 'C'};
	int		b[] = {42, 88, 207};
	float	d[] = {4.2f, -3.14f, -6.022f, 21474.0f};
	char	c;
	size_t	i;

	std::cout << _BOLD _GREY "\n🔹 Calling iter for a[] 🔹\n" _END << std::endl;

	::iter(a, sizeof(a) / sizeof(a[0]), &to_lower);
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++){
		std::cout << a[i] ;
		if (std::isalpha(a[i])) {
			c = a[i];
			std::cout << " ➡ " << c;
		}
		std::cout << std::endl;
	}


	std::cout << _BOLD _GREY "\n\n🔹 Calling iter for b[] 🔹\n" _END << std::endl;
	::iter(b, sizeof(b) / sizeof(b[0]), &to_lower);
	for (i = 0; i < sizeof(b) / sizeof(b[0]); i++) {
		std::cout << b[i] ;
		if (std::isalpha(b[i])) {
			c = b[i];
			std::cout << " ➡ " << c;
		}
		std::cout << std::endl;
	}

	std::cout << _BOLD _GREY "\n\n🔹 If size = 0 🔹" _END << std::endl;
	// No array given :
	::iter(b, 0, &to_lower);

	std::cout << _BOLD _GREY "\n🔹 Calling opposite for d[] 🔹\n" _END << std::endl;
	::iter(d, sizeof(d) / sizeof(d[0]), &opposite);
	for (i = 0; i < sizeof(d) / sizeof(d[0]); i++) {
		std::cout << d[i] << std::endl;
	}

	return 0;
}
