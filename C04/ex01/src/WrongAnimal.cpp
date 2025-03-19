/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:22:47 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/19 15:25:02 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("NoType") {
	std::cout << "WrongAnimal whitout type created" << std::endl;
}

WrongAnimal::WrongAnimal(str type): _type(type) {
	std::cout << "WrongAnimal of type " << type << " created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other): _type(other._type) {
	std::cout << "Copy of WrongAnimal of type " << other._type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal " << this->_type << " destroyed" << std::endl;
}

str WrongAnimal::getType() const {
	return (this->_type);
}

void WrongAnimal::makeSound(void) const {
	std::cout << "**no sound**" << std::endl;
}
