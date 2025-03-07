/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:16:35 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/07 15:28:02 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other._type) {
	std::cout << "Copy of Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Wouf wouf" << std::endl;
}
