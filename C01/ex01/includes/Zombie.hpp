/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:44:57 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/04 16:23:24 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

typedef std::string str;

class Zombie 
{
	private:
		str	_name;

	public:
		Zombie( void );
		Zombie(str name);
		~Zombie();
		void	announce( void );
		void	setName(str name);
};

Zombie *zombieHorde( int N, str name);
