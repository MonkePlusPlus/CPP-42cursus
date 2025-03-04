/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:09:22 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/05 00:29:27 by ptheo            ###   ########.fr       */
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
	std::map<str, int> dico;
	dico["DEBUG"] = 1;
	dico["INFO"] = 2;
	dico["WARNING"] = 3;
	dico["ERROR"] = 4;

	switch (dico.find(level)->second){
		case 1: std::cout << "[ DEBUG ]" << std::endl; debug(); std::cout << std::endl;
		case 2: std::cout << "[ INFO ]" << std::endl; info(); std::cout << std::endl;
		case 3: std::cout << "[ WARNING ]" << std::endl; warning(); std::cout << std::endl;
		case 4: std::cout << "[ ERROR ]" << std::endl; error(); std::cout << std::endl; break ;
		default: std::cout << "Complaining default" << std::endl; break ;
	}
}

