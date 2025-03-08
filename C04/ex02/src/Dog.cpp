/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:16:35 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/07 15:53:33 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog created" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other): Animal(other._type) {
	std::cout << "Copy of Dog" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destroyed" << std::endl;
	delete this->_brain;
}

void Dog::makeSound(void) const {
	std::cout << "Wouf wouf" << std::endl;
}

Brain *Dog::getBrain(void) {
	return this->_brain;
}
