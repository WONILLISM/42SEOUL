#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::_displayTimestamp(void)
{
	time_t	t;
	struct	tm	*tm;

	t = time(0);
	tm = localtime(&t);
	std::cout << std::setfill('0') << std::setw(2) << " [" << tm->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposit:" << _totalNbDeposits << ";";
	std::cout << "withdrwals:" << _totalNbWithdrawals << "\n";
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposit:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << "\n";
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created\n";
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed\n";
}
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount + deposit << ";";
	std::cout << "nb_dposits::" << this->_nbDeposits + 1 << "\n";
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits += 1;
	this->_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (_amount - withdrawal > 0)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount - withdrawal << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals + 1 << "\n";
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		this->_totalAmount -= withdrawal;
		return (true);		
	}
	std::cout << "withdrawal:refused\n";
	return (false);	
}