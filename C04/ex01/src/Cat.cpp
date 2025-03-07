/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:02:58 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/07 15:53:30 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	std::cout << "Cat created" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &other): Animal(other._type) {
	std::cout << "Copy of Cat" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destroyed" << std::endl;
	delete this->_brain;
}

void Cat::makeSound(void) const {
	std::cout << "Miaouuu.." << std::endl;
}

Brain *Cat::getBrain(void) {
	return this->_brain;
}

