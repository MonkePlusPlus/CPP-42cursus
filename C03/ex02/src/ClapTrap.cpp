/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:05:30 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/18 22:15:44 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("NoName"), _hitpoint(10), _energie(10), _attack(0) {
	std::cout << "ClapTrap without name created" << std::endl;
}

ClapTrap::ClapTrap(str name): _name(name), _hitpoint(10), _energie(10), _attack(0) {
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name), _hitpoint(other._hitpoint),
										   _energie(other._energie), _attack(other._attack)  {
	std::cout << "Copy of " << other._name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_attack = other._attack;
		this->_energie = other._energie;
		this->_hitpoint = other._hitpoint;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " is destroyed" << std::endl;
}

void ClapTrap::attack(const str& target) {
	if (this->_hitpoint < 1)
	{
		std::cout << "ClapTrap " << this->_name << " can't because it's dead..." << std::endl;
		return ;
	}
	if (this->_energie < 1) { 
		std::cout << this->_name << " doesn't have enought energie point to attack..." << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks " << target << ", causing " << this->_attack << " points of damage!" << std::endl;
	this->_energie--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitpoint < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead..." << std::endl;
		return ;
	}
	if (this->_hitpoint - amount <= 0) {
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " of damage and die!" << std::endl;
		this->_hitpoint = 0;
		return ;
	}
	std::cout << this->_name << " takes " << amount << " of damage!";
	std::cout << " His health comes from " << this->_hitpoint << " to " << this->_hitpoint - amount  << std::endl;
	this->_hitpoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitpoint < 1)
	{
		std::cout << "ClapTrap " << this->_name << " can't because it's dead..." << std::endl;
		return ;
	}
	if (this->_energie < 1) {
		std::cout << this->_name << " doesn't have enought energie point to repair..." << std::endl;
		return ;
	}
	std::cout << this->_name << " repaired " << amount << " of damage!";
	std::cout << " His health comes from " << this->_hitpoint << " to " << this->_hitpoint + amount  << std::endl;
	this->_hitpoint += amount;
	this->_energie--;
}
