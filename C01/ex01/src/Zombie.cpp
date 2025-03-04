/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:44:41 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/04 16:17:52 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) {
	return ;
};

Zombie::Zombie(str name): _name(name) {};

Zombie::~Zombie() {
	std::cout << this->_name << " is destroyed\n";
}

void	Zombie::announce( void ){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(str name){
	this->_name = name;
}
