/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:24:45 by theo              #+#    #+#             */
/*   Updated: 2025/03/08 22:36:11 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _type("NoType") {
	std::cout << "Created Materia without type" << std::endl;
}


AMateria::AMateria(std::string const & type): _type(type) {
	std::cout << "Created Materia " << type << std::endl;
}

AMateria::AMateria(const AMateria &other): _type(other._type) {
	std::cout << "Copy of Materia" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

AMateria::~AMateria() {
	std::cout << "Materia detroyed" << std::endl;
}

std::string const & AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "Use nothing" << std::endl;
}
