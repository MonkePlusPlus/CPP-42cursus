/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:08:07 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/07 15:29:38 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("NoType") {
	std::cout << "Animal whitout type created" << std::endl;
}

Animal::Animal(str type): _type(type) {
	std::cout << "Animal of type " << type << " created" << std::endl;
}

Animal::Animal(const Animal &other): _type(other._type) {
	std::cout << "Copy of Animal of type " << other._type << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal " << this->_type << " destroyed" << std::endl;
}

str Animal::getType() const {
	return (this->_type);
}

void Animal::makeSound(void) const {
	std::cout << "**no sound**" << std::endl;
}
