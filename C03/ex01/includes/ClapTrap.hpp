/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:05:27 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/18 21:59:09 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

typedef std::string str;

class ClapTrap
{
	protected:
		str	_name;
		int	_hitpoint;
		int _energie;
		int	_attack;

	public:
		ClapTrap();
		ClapTrap(str name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		virtual ~ClapTrap();

		void attack(const str& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
