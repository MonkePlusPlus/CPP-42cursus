/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:04:13 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/07 15:28:25 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other._type) {
	std::cout << "Copy of WrongCat" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "Waouuu.." << std::endl;
}