#include <iostream>
#include <string>

class Character {
public:
	virtual void	sayHello(std::string const & target);
};

class Warrior : public Character {
public:
	void	sayHello(std::string const & target);
};

class Cat {

};

void Character::sayHello(std::string const &target)
{
	std::cout << "Hello " << target << " ! " << std::endl;
}


void Warrior::sayHello(std::string const &target)
{
	std::cout << "Fuck off " << target << ", I hate you." << std::endl;
}

int main()
{
	Warrior *a = new Warrior();
	
	Character *b = new Warrior();
	// OK bc Warrior IS a Character

	// Warrior *c = new Character();
	// NOT OK because works one way, not the other

	// Character *b = new Cat();
	// NOT OK bc Cat is NOT a Character

	a->sayHello("students");
	b->sayHello("students");
}

/*
Fonction membre virtuelle = method
*/