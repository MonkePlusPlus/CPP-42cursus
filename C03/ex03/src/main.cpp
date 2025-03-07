/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:05:32 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/07 14:34:02 by ptheo            ###   ########.fr       */
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

	return (0);
}
