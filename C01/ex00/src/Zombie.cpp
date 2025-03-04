/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:44:41 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/04 16:06:43 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(str name): name(name) {}

Zombie::~Zombie() {
	std::cout << this->name << " is destroyed\n";
}

void	Zombie::announce( void ){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}
