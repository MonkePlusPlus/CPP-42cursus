/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:16:16 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/04 17:39:46 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(str type): _type(type) {};

Weapon::Weapon(void){};

Weapon::~Weapon(void){};


str	const &Weapon::getType() const {
	return (this->_type);
}

void	Weapon::setType(str type) {
	this->_type = type;
}
