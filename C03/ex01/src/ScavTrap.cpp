/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:31:58 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/06 21:26:08 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): _name("NoName"), _health(10), _energie(10), _attack(0) {
	std::cout << "ScavTrap without name created" << std::endl;
}

ScavTrap::ScavTrap(str name): _name(name), _health(10), _energie(10), _attack(0) {
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): _name(other._name), _health(other._health),
										   _energie(other._energie), _attack(other._attack)  {
	std::cout << "Copy of " << other._name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_attack = other._attack;
		this->_energie = other._energie;
		this->_health = other._health;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " is destroyed" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode" << std::endl;
}
