#include "colors.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "wrongAnimal.hpp"
#include "wrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	std::cout << "\nWhat's the type of this Animal ? It's a " _SALMON << i->getType() <<  _END " !" << std::endl;
	std::cout << "What's the type of this Animal ? It's a " _RIVIERA << j->getType() << _END " !\n" << std::endl;

	std::cout << "The Animal goes : ";
	meta->makeSound();
	std::cout << std::endl;
	std::cout << "The Cat goes : ";
	i->makeSound();
	std::cout << std::endl; //will output the cat sound!
	std::cout << "The Dog goes : ";
	j->makeSound();
	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;

	const wrongCat* wrongOne = new wrongCat();
	std::cout << "\nWhat's the type of this Animal ? It's a " _BROWN << wrongOne->getType() <<  _END " !" << std::endl;
	std::cout << "This one goes : ";
	wrongOne->makeSound();
	std::cout << std::endl;
	delete wrongOne;

	// class wrongCat inherited from wrongAnimal which doesn't have 'virtual' functions
	// As a result : wrongSecond runs back to methos from wrongAnimal, and not its own functions

	const wrongAnimal* wrongSecond = new wrongCat();
	std::cout << "\nWhat's the type of this Animal ? It's a " _BROWN << wrongSecond->getType() <<  _END " !" << std::endl;
	std::cout << "This one goes : ";
	wrongSecond->makeSound();
	std::cout << std::endl;
	delete wrongSecond;

	return 0;
}