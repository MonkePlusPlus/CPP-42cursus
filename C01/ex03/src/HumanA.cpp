/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:22:26 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/04 17:47:12 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(str name, Weapon &weapon):  _weapon(weapon), _name(name) {};

void HumanA::setWeapon(Weapon &weapon) {
	this->_weapon = weapon;
}

void HumanA::attack(){
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
