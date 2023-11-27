#include "colors.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
 
int main()
{

	// std::cout << "\n---------------- ";
	// std::cout << " FIRST TEST ";
	// std::cout << " ----------------\n" << std::endl;
	std::cout << _BLINK _ITALIC _GREY "\n---------------- ";
	std::cout << " NEW PLAYER ";
	std::cout << " ----------------\n" _END << std::endl;
	IMateriaSource* spellBook = new MateriaSource();
	std::cout << _ITALIC _GREY "Creating new Character :" _END << std::endl;
	ICharacter* Chara1 = new Character("Wan");
	std::cout << _ITALIC _GREY "Filling SpellBook :" _END << std::endl;
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());
	AMateria* tmp;
	std::cout << _ITALIC _GREY "Creating a new Materia" _END << std::endl;
	tmp = spellBook->createMateria("ice");
	std::cout << _ITALIC _GREY "Learning an already known spell :" _END << std::endl;
	spellBook->learnMateria(new Cure());
	std::cout << _ITALIC _GREY "Equipping Player : " _END << std::endl;
	Chara1->equip(tmp);


	AMateria* tmp2;
	tmp2 = spellBook->createMateria("cure");
	
	std::cout << _ITALIC _GREY "Filling Inventory :" _END << std::endl;
	Chara1->equip(tmp2);
	Chara1->equip(tmp);
	Chara1->equip(tmp2);
	Chara1->equip(tmp);
	Chara1->equip(tmp2);
	std::cout << _BLINK _ITALIC _GREY "\n---------------- ";
	std::cout << " NEW PLAYER ";
	std::cout << " ----------------\n" _END << std::endl;
	ICharacter* Chara2 = new Character("Grint");

	std::cout << _ITALIC _GREY "First Player uses ICE on Second Player" _END << std::endl;
	Chara1->use(0, *Chara2);
	std::cout << _ITALIC _GREY "First Player uses CURE on Second Player" _END << std::endl;
	Chara1->use(1, *Chara2);

	std::cout << _ITALIC _GREY "Unequipping then using slot nº0 of the inventory :" _END << std::endl;
	Chara1->unequip(0);
	Chara1->use(0, *Chara2);
	

	std::cout << _ITALIC _GREY "Equipping second player :" _END << std::endl;
	Chara2->equip(tmp2);
	Chara2->equip(tmp);
	std::cout << _ITALIC _GREY "Second Player uses ICE on First Player" _END << std::endl;
	Chara2->use(1, *Chara1);
	std::cout << _ITALIC _GREY "Trying slot nº8 of the inventory :" _END << std::endl;
	Chara2->use(8, *Chara1);
	Chara2->equip(tmp2);

	delete tmp;
	delete tmp2;
	delete Chara1;
	delete Chara2;
	delete spellBook;
	return 0;
}

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	delete tmp;

// 	AMateria* tmp2;
// 	tmp2 = src->createMateria("cure");
// 	me->equip(tmp2);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete tmp2;
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }