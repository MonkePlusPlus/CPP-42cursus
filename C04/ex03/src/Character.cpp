/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:34:47 by theo              #+#    #+#             */
/*   Updated: 2025/03/08 22:58:04 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("NoName") {
	std::cout << "Character created without name" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inv[i] = NULL;
	}
}

Character::Character(std::string name): _name(name) {
	std::cout << "Character " << name << " created" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inv[i] = NULL;
	}
}

Character::Character(const Character &other): _name(other._name) {
	std::cout << "Character " << other._name <<" copy" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inv[i] = other._inv[i];
	}
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (this->_inv[i] != NULL)
				delete this->_inv[i];
			this->_inv[i] = other._inv[i];
		}
	}
	return *this;
}

Character::~Character() {
	std::cout << "Character " << this->_name << " destroyed" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_inv[i] != NULL)
			delete this->_inv[i];
	}
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_inv[i] == NULL) {
			this->_inv[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	this->_inv[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	this->_inv[idx]->use(target);
}
