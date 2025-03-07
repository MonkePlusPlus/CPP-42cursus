/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:05:32 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/07 14:18:12 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
	ClapTrap claptrap("Claptrap");
	ClapTrap claptrap2("Claptrap2");

	ScavTrap scavtrap("ScavTrap");
	ScavTrap scavtrap2("ScavTrap2");

	FragTrap fragtrap("FragTrap");
	FragTrap fragtrap2("FragTrap2");

	claptrap.attack("Jack");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);

	claptrap2.attack("Jack");
	claptrap2.takeDamage(10);
	claptrap2.beRepaired(5);

	scavtrap.attack("Jack");
	scavtrap.takeDamage(10);
	scavtrap.beRepaired(5);
	scavtrap.guardGate();

	scavtrap2.attack("Jack");
	scavtrap2.takeDamage(10);
	scavtrap2.beRepaired(5);

	fragtrap.attack("Jack");
	fragtrap.takeDamage(10);
	fragtrap.beRepaired(5);
	fragtrap.highFiveGuys();

	fragtrap2.attack("Jack");
	fragtrap2.takeDamage(10);
	fragtrap2.beRepaired(5);
	fragtrap2.highFiveGuys();

	return (0);
}
