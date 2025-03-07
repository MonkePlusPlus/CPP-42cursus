/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:05:30 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/07 13:57:29 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("NoName"), _health(10), _energie(10), _attack(0) {
	std::cout << "ClapTrap without name created" << std::endl;
}

ClapTrap::ClapTrap(str name): _name(name), _health(10), _energie(10), _attack(0) {
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name), _health(other._health),
										   _energie(other._energie), _attack(other._attack)  {
	std::cout << "Copy of " << other._name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_attack = other._attack;
		this->_energie = other._energie;
		this->_health = other._health;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " is destroyed" << std::endl;
}

void ClapTrap::attack(const str& target) {
	if (this->_energie < 1) { 
		std::cout << this->_name << " doesn't have enought energie point to attack..." << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks " << target << ", causing " << this->_attack << " points of damage!" << std::endl;
	this->_energie--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_health - amount <= 0) {
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " of damage and die!" << std::endl;
		this->_health = 0;
		return ;
	}
	std::cout << this->_name << " takes " << amount << " of damage!";
	std::cout << " His health comes from " << this->_health << " to " << this->_health - amount  << std::endl;
	this->_health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energie < 1) {
		std::cout << this->_name << " doesn't have enought energie point to repair..." << std::endl;
		return ;
	}
	std::cout << this->_name << " repaired " << amount << " of damage!";
	std::cout << " His health comes from " << this->_health << " to " << this->_health + amount  << std::endl;
	this->_health += amount;
	this->_energie--;
}
