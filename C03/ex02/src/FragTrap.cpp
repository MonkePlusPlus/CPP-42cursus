/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:00:34 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/07 14:04:58 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("NoName") {
	this->_health = 100;
	this->_energie = 100;
	this->_attack = 30;
	std::cout << "FragTrap without name created" << std::endl;
}

FragTrap::FragTrap(str name): ClapTrap(name) {
	this->_health = 100;
	this->_energie = 100;
	this->_attack = 30;
	std::cout << "FragTrap " << name << " created for sure" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other._name) {
	this->_health = other._health;
	this->_energie = other._energie;
	this->_attack = other._attack;
	std::cout << "Copy of " << other._name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_attack = other._attack;
		this->_energie = other._energie;
		this->_health = other._health;
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " is destroyed horribly" << std::endl;
}

void FragTrap::attack(str name) {
	if (this->_energie < 1) {
		std::cout << this->_name << " doesn't have enought energie point to attack..." << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks " << name << " hard and does " << this->_attack << " of damage!" << std::endl; 
}

void FragTrap::highFiveGuys() {
	std::cout << "FragTrap " << this->_name << " says hight to five guys" << std::endl;
}
