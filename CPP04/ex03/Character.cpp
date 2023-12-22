#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "colors.hpp"

Character::Character(): _name("Random Name"), _takenSpots(0) {

	// std::cout << _ITALIC "Character Constructor called" _END << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
	return;
}

Character::Character(std::string const & name) : _name(name), _takenSpots(0) {

	// std::cout << _ITALIC "Character String Parametric Constructor called" _END << std::endl;
	std::cout << _ITALIC _LAGOON << this->_name << " joined the party ヾ(・u・) \n" _END << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
	return;
}

Character::Character( Character const & src ) : _name(src._name), _takenSpots(0) {

	// std::cout << _ITALIC "Character Copy Constructor called" _END << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = src._inventory[i];
		_inventory[i]->setType(src._inventory[i]->getType());
	}
	*this = src;
	return;
}

Character::~Character(void) {

	// std::cout << _ITALIC "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	return;
}

Character & Character::operator=( Character const & rhs ) {
	
	// std::cout << _ITALIC "Character Copy Assignement operator called" _END << std::endl;
	if (this != &rhs)
		this->_name = rhs._name;
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m) {
	
	if (!m)
	{
		std::cout << "Chosen equipment is empty ❌" << std::endl;
		std::cout << "Give me something to pick up, I'm ready (・_・)ノ \n" << std::endl;
		return;
	}

	int i = 0;
	while (_inventory[i] != 0 && i < 4)
		i++;
	if (i >= 4 || _takenSpots >= 4)
	{
		std::cout << "INVENTORY IS FULL ❌" << std::endl;
		std::cout << _SALMON "You need to empty a slot before you equip something new (ಠ‾ಠ) \n" _END << std::endl;
		return;
	}
	this->_inventory[i] = m->clone();
	_takenSpots++;
	std::cout << this->_name << " can now use " _BOLD _ITALIC _RIVIERA << m->getType() << _END " ! ";
	std::cout << "It's placed nº" << i << " in " << this->getName() << "'s inventory 🎒\n" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
	{
		std::cout << "Inventory only has 4 slots ❌\n" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == 0)
		std::cout << "This slot is already empty ! ❌\n" << std::endl;
	else
	{
		std::cout << "Spot nº" << idx << " of the inventory is now empty ! ";
		std::cout << this->_name << " can no longer use " << _BOLD _ITALIC _RIVIERA;
		std::cout << this->_inventory[idx]->getType() << _END "\n" << std::endl;
		delete this->_inventory[idx];
		this->_inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target) {

	if (idx < 0 || idx > 3)
	{
		std::cout << "Inventory only has 4 slots ❌\n" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == 0)
	{
		std::cout << "Empty slot in inventory ❌\n" << std::endl;
		return ;
	}
	std::cout << _BOLD << this->_name << _END " ";
	this->_inventory[idx]->use(target);
}