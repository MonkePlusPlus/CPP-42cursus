/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:37:42 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/07 15:54:02 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &other) {
	for (int i = 0; i < 100; i++){
			this->idea[i] = other.idea[i]; 
	}
	std::cout << "Brain copy" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++){
			this->idea[i] = other.idea[i]; 
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain detroyed" << std::endl;
}
