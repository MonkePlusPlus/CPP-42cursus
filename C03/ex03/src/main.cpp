/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:05:32 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/18 22:36:58 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(){
	DiamondTrap diamondtrap = DiamondTrap("DiamondTrap");
	DiamondTrap diamondtrap2 = DiamondTrap("DiamondTrap2");

	diamondtrap.attack("John");
	diamondtrap.beRepaired(50);
	diamondtrap.takeDamage(20);
	diamondtrap.whoAmI();
	diamondtrap.guardGate();
	diamondtrap.highFiveGuys();

	return (0);
}
