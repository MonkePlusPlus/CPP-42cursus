/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:37:58 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/04 17:39:51 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

typedef std::string str;

class Weapon
{
	public:
		Weapon(str type);
		Weapon();
		~Weapon();
		str const &getType() const;
		void setType(str type);

	private:
		str _type;
};
