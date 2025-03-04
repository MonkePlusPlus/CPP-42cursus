/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:15:46 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/04 17:47:44 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

typedef std::string str;

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(str name);
		void setWeapon(Weapon &weapon);
		void attack();

	private:
		str _name;
		Weapon *_weapon;
};
