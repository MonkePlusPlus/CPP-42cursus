/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:15:48 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/04 17:46:52 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "Weapon.hpp"

typedef std::string str;

class HumanA
{
	public:
		HumanA(str name, Weapon &weapon);
		void setWeapon(Weapon &weapon);
		void attack();

	private:
		Weapon &_weapon;
		str _name;
};
