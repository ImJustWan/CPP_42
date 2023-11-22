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
	
	void				setNrgPoints(unsigned int amount);
	void				setAtkDmg(unsigned int amount);
	const std::string	&getName() const;

protected:
	std::string	_name;
	int			_hitPts;
	int			_nrgPts;
	int			_atkDmg;

private:

};

#endif