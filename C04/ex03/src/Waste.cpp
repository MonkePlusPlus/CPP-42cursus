/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Waste.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:38:56 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/19 16:04:16 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Waste.hpp"

Waste::Waste(): head(NULL) {
	std::cout << "Create Waste" << std::endl;
}

Waste::~Waste() {
	std::cout << "Destroyed Waste" << std::endl;
}

Waste::Waste(const Waste &other) {
	*this = other;
}

Waste	&Waste::operator=(const Waste &other) {
	if (this != &other){
		this->freeWaste();
		this->head = other.head;
	}
	return (*this);
}

void	Waste::freeWaste() {
	Node *tmp = this->head;
	Node *current = tmp->next;
	
	while (current){
		delete tmp->data;
		delete tmp;
		tmp = current;
		current = tmp->next;
	}
	if (tmp) {
		delete tmp->data;
		delete tmp;
	}
}

void	Waste::addWaste(AMateria *waste) {
	Node *tmp = this->head;

	if (tmp == NULL)
	{
		this->head = new Node();
		this->head->data = waste;
		this->head->next = NULL;
		return ;
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new Node();
	tmp->next->data = waste;
	tmp->next->next = NULL;
}
