/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:24:42 by theo              #+#    #+#             */
/*   Updated: 2025/03/08 22:56:42 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {
	std::cout << "Default Cure created" << std::endl;
}

Cure::Cure(const Cure &other): AMateria(other._type) {
	std::cout << "Copy Cure created" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

Cure::Cure(std::string const & type): AMateria(type) {
	std::cout << "Type Cure created" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destroyed" << std::endl;
}

Cure* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
