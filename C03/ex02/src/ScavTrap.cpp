/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:31:58 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/18 22:19:29 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("NoName") {
	this->_hitpoint = 100;
	this->_energie = 50;
	this->_attack = 20;
	std::cout << "ScavTrap without name created" << std::endl;
}

ScavTrap::ScavTrap(str name): ClapTrap(name) {
	this->_hitpoint = 100;
	this->_energie = 50;
	this->_attack = 20;
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other._name) {
	this->_hitpoint = other._hitpoint;
	this->_energie = other._energie;
	this->_attack = other._attack;
	std::cout << "Copy of " << other._name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_attack = other._attack;
		this->_energie = other._energie;
		this->_hitpoint = other._hitpoint;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " is destroyed" << std::endl;
}

void ScavTrap::attack(const str& target) {
	if (this->_hitpoint < 1)
	{
		std::cout << "ScavTrap " << this->_name << " can't because it's dead..." << std::endl;
		return ;
	}
	if (this->_energie < 1) {
		std::cout << this->_name << " doesn't have enought energie point to attack..." << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks " << target << " hard and does " << this->_attack << " of damage!" << std::endl; 
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode" << std::endl;
}
