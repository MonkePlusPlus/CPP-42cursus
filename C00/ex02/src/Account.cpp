/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:16:11 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/03 22:17:56 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ): 
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
}

Account::Account( void ): 
	_accountIndex(_nbAccounts),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
	this->_nbAccounts++;
}

Account::~Account( void ){
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}


void	Account::_displayTimestamp( void ) {
	char buf[80];
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", now);
	std::cout << buf;
}


void	Account::makeDeposit( int deposit ) {
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:"
		<< deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (this->_amount < withdrawal){
		std::cout << "refused\n";
		return (false);
	}
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	_totalAmount -= withdrawal;
	std::cout << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	return (true);
}

int		Account::checkAmount( void ) const {
	return (0);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
		 << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int	Account::getNbAccounts( void ){
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" 
		<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
