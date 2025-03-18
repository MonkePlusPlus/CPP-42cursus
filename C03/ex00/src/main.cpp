/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:05:32 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/18 22:00:18 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){
	ClapTrap claptrap("Claptrap");
	ClapTrap claptrap2("Claptrap2");

	claptrap.attack("Jack");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);

	claptrap2.attack("Jack");
	claptrap2.takeDamage(10);
	claptrap2.beRepaired(5);

	return (0);
}
