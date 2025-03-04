/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:53:21 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/04 16:06:21 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(str name );
void randomChump( str name );

int	main( void ) {
	Zombie *a = newZombie("Iyan");

	a->announce();
	randomChump("Yo");
	delete(a);
	return (0);
}