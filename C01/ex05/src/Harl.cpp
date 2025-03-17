/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:09:22 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/14 19:06:34 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


Harl::Harl(){};

Harl::~Harl(){};

void Harl::debug(void){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(str level){
	std::map<str, void (Harl::*)(void)> dico;
	dico["DEBUG"] = &Harl::debug;
	dico["INFO"] = &Harl::info;
	dico["WARNING"] = &Harl::warning;
	dico["ERROR"] = &Harl::error;

	if (dico.find(level) == dico.end()){
		std::cout << "Wrong level" << std::endl;
		return ;
	}
	(this->*dico[level])();
}

