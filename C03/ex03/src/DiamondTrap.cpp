/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:22:13 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/18 22:34:38 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"



DiamondTrap::DiamondTrap(): ClapTrap("NoName_clap_name"), ScavTrap("NoName_scav_name"), FragTrap("NoName_frag_name"){
	this->_name = "NoName";
	this->_hitpoint = FragTrap::_hitpoint;
	this->_energie = ScavTrap::_energie;
	this->_attack = FragTrap::_hitpoint;
	std::cout << "DiamondTrap without name created" << std::endl;
}

DiamondTrap::DiamondTrap(str name): ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name") {
	this->_name = name;
	this->_hitpoint = FragTrap::_hitpoint;
	this->_energie = ScavTrap::_energie;
	this->_attack = FragTrap::_hitpoint;
	std::cout << "DiamondTrap " << name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other._name + "_clap_name"), ScavTrap(other._name + "_scav_name"), FragTrap(other._name + "_frag_name") {
	this->_name = other._name;
	this->_hitpoint = other._hitpoint;
	this->_energie = other._energie;
	this->_attack = other._attack;
	std::cout << "Copy of " << other._name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other._name + "_clap_name");
		ScavTrap::operator=(other._name + "_scav_name");
		FragTrap::operator=(other._name + "_frag_name");
		this->_name = other._name;
		this->_attack = other._attack;
		this->_energie = other._energie;
		this->_hitpoint = other._hitpoint;
	}
	return (*this);
}

void DiamondTrap::attack(const str &target) {
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " is destroyed" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap " << this->_name << " don't know who it is" << std::endl;
}
