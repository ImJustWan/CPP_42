#include <string>

class Cat {

public:
	Cat();
	Cat( Cat const &);
	Cat &operator=( Cat const &);
	~Cat();

	void	run(int distance);
	void	scornSomeone(std::string const & target);

private:
	int		_numberOfLegs;

};

class Pony {

public:
	Pony();
	Pony( Pony const &);
	Pony &operator=( Pony const &);
	~Pony();

	void	run(int distance);
	void	doMagic(std::string const & target);

private:
	int		_numberOfLegs;

};
