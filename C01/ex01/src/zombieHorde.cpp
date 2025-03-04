/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:08:21 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/04 16:21:10 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, str name ){
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++){
		horde[i].setName(name);
	}
	return (horde);
}