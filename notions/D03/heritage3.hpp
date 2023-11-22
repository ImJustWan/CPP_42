#include <string>

class Quadruped
{
	private:
		std::string name; // accessible from Quad. object

	protected:
		Leg			legs[4]; // accessible from Quad. OR derived object
	public:
		void		run(); // accessible from wherever

};

class Dog : public Quadruped
{

};