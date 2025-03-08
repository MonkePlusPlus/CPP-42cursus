/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:24:47 by theo              #+#    #+#             */
/*   Updated: 2025/03/08 22:41:42 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {
	std::cout << "Default Ice created" << std::endl;
}

Ice::Ice(const Ice &other): AMateria(other._type) {
	std::cout << "Copy Ice created" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

Ice::Ice(std::string const & type): AMateria(type) {
	std::cout << "Type Ice created" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destroyed" << std::endl;
}

Ice* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
