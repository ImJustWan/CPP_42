#include <iostream>

class Foo {

	public :

		Foo(float const v) : _v(v) {}

		float	getV()		{return this->_v;}

		operator float()	{return this->_v;}
		operator int()		{return static_cast<int>(this->_v);}

	private:
		float _v;
};

int main()
{
	Foo	a(420.042f);
	float	b = a;	// cast implicit
	int		c = a;	// cast implicit

	std::cout << "a is : " << a.getV() << std::endl;
	std::cout << "b is : " << b << std::endl;
	std::cout << "c is : " << c << std::endl;
	return 0;
}0