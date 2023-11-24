#include "colors.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "wrongAnimal.hpp"
#include "wrongCat.hpp"

int main()
{
	const Animal* kittie = new Cat("🐟🐟🐟");
	const Animal* doggo = new Dog("🦴🦴🦴");

	std::cout << "\nDog thoughts n.8 : " << doggo->getIdea(8) << std::endl;
	std::cout << "Cat thoughts n.89 : " << kittie->getIdea(89) << "\n" << std::endl;

	const Animal *doubleDoggo = new Dog(*(Dog *)doggo);

	delete kittie;	
	delete doggo;

	// This lain creates a segfault because doogo went back to doggo's paradise
	// std::cout << "Dog thoughts : " << doggo->getIdea(8) << std::endl;
	std::cout << "doubleDog thoughts : " << doubleDoggo->getIdea(8) << std::endl;

	delete doubleDoggo;

	std::cout << "\n------------------------";
	std::cout << "------------------------\n" << std::endl;

	Animal *cagez[8];
	for (int boop = 0; boop < 8; boop++)
	{
		if (boop < 4)
			cagez[boop] = new Dog();
		else
			cagez[boop] = new Cat();
		
	}

	std::cout << "\n------------------------\n" << std::endl;

	for (int woop = 0; woop < 8; woop++)
	{
		if (woop < 4)
			std::cout << "🐕";
		else
			std::cout << "🐈";
		if (woop % 2 == 0)
			std::cout << _RIVIERA;
		else
			std::cout << _SALMON;
		delete cagez[woop];
		std::cout << _END;

	}	

	std::cout << "\n------------------------";
	std::cout << "------------------------\n" << std::endl;

	// -> if a class is a parent and has at least a virtual function, virtual destructor is mandatory  
	// If the destructor in the parent class were not declared as virtual, deleting the object through a parent class pointer
	// would only call the destructor of the parent class, not the child class. 

	// Uncomment for compilation error :
	// " error: delete called on non-final 'wrongAnimal' that has virtual functions but non-virtual destructor"

	// const wrongAnimal* wrongSecond = new wrongCat();
	// std::cout << "\nWhat's the type of this Animal ? It's a " _BROWN << wrongSecond->getType() <<  _END " !" << std::endl;
	// std::cout << "This one goes : ";
	// wrongSecond->makeSound();
	// std::cout << std::endl;
	// delete wrongSecond;

	return 0;
}