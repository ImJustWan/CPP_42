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
	std::cout << "\ndoubleDog thoughts : " << doubleDoggo->getIdea(8) << "\n" << std::endl;

	delete doubleDoggo;

	
	// Class Animal is abstract because of getIdea() = 0, blocking the creation of an instance
	// uncomment for error compilation :
		// "error: allocating an object of abstract class type 'Animal'"
		// "unimplemented pure virtual method 'getIdea' in 'Animal'"

	// const Animal *randomOne = new Animal();
	// delete (randomOne);
	
	return 0;
}