#include <string>

class Animal {

public:
	Animal();
	Animal( Animal const &);
	Animal &operator=( Animal const &);
	~Animal();

	void	run(int distance);

private:
	int		_numberOfLegs;

};

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &);
		Cat &operator=( Cat const &);
		~Cat();

		void	scornSomeone(std::string const & target);
};

class Pony : public Animal
{
	public:
		Pony();
		Pony( Pony const &);
		Pony &operator=( Pony const &);
		~Pony();
		
		void	doMagic(std::string const & target);
};
