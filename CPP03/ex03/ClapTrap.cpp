#include "ClapTrap.hpp"
#include "colors.hpp"

ClapTrap::ClapTrap() : _hitPts(10), _nrgPts(10), _atkDmg(0) {

	std::cout << _ITALIC "ClapTrap Constructor called" _END << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name),  _hitPts(10), _nrgPts(10), _atkDmg(0) {
	
	std::cout << _ITALIC "ClapTrap String Parametric Constructor called (" << name << ")" _END << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap const & src ) : _name(src._name) {

	std::cout << _ITALIC "Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

ClapTrap::~ClapTrap(void) {

    std::cout << _ITALIC "ClapTrap Destructor called (" << getName() << ")" _END << std::endl;
    return;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & n ) {
	
	std::cout << _ITALIC "ClapTrap Copy Assignement operator called" _END << std::endl;
	_name = n._name;
	return *this;

}

void	ClapTrap::setAtkDmg(unsigned int amount) {
	std::cout << _ITALIC _GREY _BLINK "🔹 Setting " << getName() << " Attack Damages : " << _atkDmg << " ➔ " << amount << "🔹\n" _END << std::endl;
	_atkDmg = amount;
}

void	ClapTrap::setNrgPoints(unsigned int amount) {
	std::cout << _ITALIC _GREY _BLINK "🔹 Setting " << getName() << " Energy points : " << _nrgPts << " ➔ " << amount << "🔹\n" _END << std::endl;
	_nrgPts = amount;
}

const std::string	&ClapTrap::getName(void) const {
	return _name;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_nrgPts > 0)
	{
		std::cout << _BOLD _SALMON "\n" << getName() <<"(ClapTrap) attacks ! (ง'̀-'́)ง " _END << std::endl;
		if (_hitPts == 0)
		{
			std::cout << "ClapTrap has no Hit Points left, the attack failed..." << std::endl;
			return;
		}
		std::cout << target << " was punched ヾ(￣□￣)ﾂ" << std::endl;
		takeDamage(_atkDmg);
		std::cout << _ITALIC _GREY "(attack cost) " << getName() << " Energy points : " << _nrgPts;
		_nrgPts--;
		std::cout << " ➔ " << _nrgPts << "\n" _END << std::endl;
	}
	else
		std::cout << getName() << " has no Energy points left, they can't attack ε-(´・｀)\n" << std::endl;

}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "They took " << amount << " hit points." << std::endl;
	if (amount < 3)
		std::cout << _FOREST_GREEN "It didn't hurt very much..." _END << std::endl;
	else
		std::cout << _RED "Aouch, felt that ಥ_ಥ" _END << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_nrgPts > 0)
	{
		std::cout << _CYAN _ITALIC _BOLD << getName() << " is drinking a Potion 🧪 ";
		std::cout << _ITALIC << getName() << " Hit points : " << _hitPts;
		_hitPts += amount;
		std::cout << " ➔ " << _hitPts << _END <<std::endl;
		std::cout << _ITALIC _GREY "(repair cost) " << getName() << " Energy points : " << _nrgPts;
		_nrgPts--;
		std::cout << " ➔ " << _nrgPts << "\n" _END << std::endl;
	}
	else
		std::cout << getName() << " has no Energy points left ε-(´・｀)" << std::endl;
}
