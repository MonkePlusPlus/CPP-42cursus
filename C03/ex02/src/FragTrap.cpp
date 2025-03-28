/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:00:34 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/18 22:19:07 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("NoName") {
	this->_hitpoint = 100;
	this->_energie = 100;
	this->_attack = 30;
	std::cout << "FragTrap without name created" << std::endl;
}

FragTrap::FragTrap(str name): ClapTrap(name) {
	this->_hitpoint = 100;
	this->_energie = 100;
	this->_attack = 30;
	std::cout << "FragTrap " << name << " created for sure" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other._name) {
	this->_hitpoint = other._hitpoint;
	this->_energie = other._energie;
	this->_attack = other._attack;
	std::cout << "Copy of " << other._name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_attack = other._attack;
		this->_energie = other._energie;
		this->_hitpoint = other._hitpoint;
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " is destroyed horribly" << std::endl;
}

void FragTrap::highFiveGuys() {
	std::cout << "FragTrap " << this->_name << " wants a hight five" << std::endl;
}
