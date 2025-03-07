/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:22:13 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/07 14:48:53 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"



DiamondTrap::DiamondTrap(): ClapTrap("NoName_clap_name"), ScavTrap("NoName"), FragTrap("NoName"){
	this->_name = "NoName";
	this->_health = FragTrap::_health;
	this->_energie = ScavTrap::_energie;
	this->_attack = FragTrap::_health;
	std::cout << "DiamondTrap without name created" << std::endl;
}

DiamondTrap::DiamondTrap(str name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->_name = name;
	this->_health = FragTrap::_health;
	this->_energie = ScavTrap::_energie;
	this->_attack = FragTrap::_health;
	std::cout << "DiamondTrap " << name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other._name + "clap_name"), ScavTrap(other._name), FragTrap(other._name) {
	this->_name = other._name;
	this->_health = other._health;
	this->_energie = other._energie;
	this->_attack = other._attack;
	std::cout << "Copy of " << other._name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other._name + "clap_name");
		ScavTrap::operator=(other._name);
		FragTrap::operator=(other._name);
		this->_name = other._name;
		this->_attack = other._attack;
		this->_energie = other._energie;
		this->_health = other._health;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " is destroyed" << std::endl;
}

void DiamondTrap::attack(const str &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap " << this->_name << " don't know who it is" << std::endl;
}
