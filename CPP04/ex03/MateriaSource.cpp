#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "colors.hpp"

MateriaSource::MateriaSource() : _nbSpells(0) {

	// std::cout << _ITALIC "MateriaSource Constructor called" _END << std::endl;
	for (int i = 0; i < 4; i++)
		_spellBook[i] = 0;
	return;
}

MateriaSource::MateriaSource( MateriaSource const & src ) : _nbSpells(0) {

	// std::cout << _ITALIC "MateriaSource Copy Constructor called" _END << std::endl;
    *this = src;
	for (int i = 0; i < 4; i++)
		_spellBook[i] = src._spellBook[i]->clone();
	return;
}

MateriaSource::~MateriaSource(void) {

    // std::cout << _ITALIC "MateriaSource Destructor called" << std::endl;
    for (int i = 0; i < _nbSpells && i < 4; i++)
		if (this->_spellBook[i])
			delete this->_spellBook[i];
	return;
}

MateriaSource & MateriaSource::operator=( MateriaSource const & rhs ) {
	
	// std::cout << _ITALIC "MateriaSource Copy Assignement operator called" _END << std::endl;
	if (this != &rhs)
		for (int i = 0; i < 4; i++)
			this->_spellBook[i] = rhs._spellBook[i]->clone();
	return *this;

}

void	MateriaSource::learnMateria(AMateria* m) {
	int i = 0;
	while (_spellBook[i] != 0 && i < 4)
	{
		if (_spellBook[i]->getType() == m->getType())
		{
			std::cout << "Already know that one " _LAGOON _ITALIC _BOLD "(" << m->getType() << ")" _END ", we should learn something new ! ❌\n" << std::endl;
			delete m;
			return;
		}
		i++;
	}
	if (i >= 4 || _nbSpells >= 4)
	{
		std::cout << "I'm full, I can't learn anymore （； ￣Д￣）" << std::endl;
		return;
	}
	_spellBook[i] = m;
	_nbSpells++;
	std::cout << "SpellBook now holds the secret of " _BOLD _ITALIC _RIVIERA;
	std::cout << m->getType() << "\n" _END << std::endl;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {

	if (_nbSpells == 0)
	{
		std::cout << "I know that I know nothing ＼（－－）／" << std::endl;
		return 0;
	}
	for (int i = 0; i < _nbSpells && i < 4; i++)
	{
		if (_spellBook[i]->getType() == type)
		{
			std::cout << _BOLD _ITALIC _RIVIERA << type << _END " was created ! ";
			std::cout << "You should pick it up before someone else takes it (≖_≖ )\n" << std::endl;
			return _spellBook[i]->clone();
		}
	}
	std::cout << "I haven't learnt that one yet, chief ! (╥﹏╥)" << std::endl;
	return 0;
}