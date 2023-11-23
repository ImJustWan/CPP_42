#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

public:

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap();

	ClapTrap & operator=( ClapTrap const & rhs );

	void				attack(const std::string& target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	
	void				setNrgPoints(const unsigned int amount);
	void				setAtkDmg(const unsigned int amount);
	const std::string	&getName() const;

private:
	std::string	_name;
	int			_hitPts;
	int			_nrgPts;
	int			_atkDmg;


};

#endif