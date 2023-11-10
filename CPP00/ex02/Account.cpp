#include "Account.hpp"
#include <iostream>
// #include <chrono>

Account::Account( int initial_deposit ) : _amount( initial_deposit ) {

	// std::cout << "Constructor called" << std::endl;	
	_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	_nbAccounts++;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
	Account::_totalAmount += initial_deposit;
	return;
}

Account::~Account( void ) {

		_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";closed" << std::endl;

	return;
}

int	Account::getNbAccounts( void ) {

	return Account::_nbAccounts;
	// return 0;
}

int	Account::getTotalAmount( void ) {

	return Account::_totalAmount;
	// return 0;
}

int	Account::getNbDeposits( void ) {

	// std::cout << "nb deposits: " << Account::_totalNbDeposits ;
	return Account::_totalNbDeposits;
	// return 8;
}

int	Account::getNbWithdrawals( void ) {

	return Account::_totalNbWithdrawals;
	// return 0;
}

void	Account::_displayTimestamp( void ) {


	time_t now = time(0);
	tm *ltm = localtime(&now);

	std::cout << "[";
	std::cout << 1900 + ltm->tm_year << 1 + ltm->tm_mon << ltm->tm_mday << "_";
	std::cout << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "] ";
}

void	Account::displayAccountsInfos( void ) {

	_displayTimestamp();
	/*for each account*/
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
	return;
}

void	Account::makeDeposit( int deposit ) {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	
	return;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount)
		std::cout << ";withdrawal:refused" << std::endl;
	else
	{		
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << this->_amount;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		Account::_totalNbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
	}
	return 0;
}

int	Account::checkAmount( void ) const {

	return this->_amount;
}

void	Account::displayStatus( void ) const {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

