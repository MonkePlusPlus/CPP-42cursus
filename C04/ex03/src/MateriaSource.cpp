/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:34:58 by theo              #+#    #+#             */
/*   Updated: 2025/03/08 22:55:54 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "Default MateriaSource created" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_mat[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	std::cout << "Copy MateriaSource created" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_mat[i] = other._mat[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) { 
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (this->_mat[i] != NULL)
				delete this->_mat[i];
			this->_mat[i] = other._mat[i];
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destroyed" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_mat[i] != NULL)
			delete this->_mat[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_mat[i] == NULL){
			this->_mat[i] = m;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->_mat[i] != NULL && this->_mat[i]->getType() == type){
			return this->_mat[i]->clone();
		}
	}
	return NULL;
}
