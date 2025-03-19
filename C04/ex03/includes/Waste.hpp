/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Waste.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:34:24 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/19 15:53:21 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AMateria.hpp"

class AMateria;

struct Node {
    AMateria *data;  
    Node* next; 
};

class Waste
{
	public:
		Waste();
		~Waste();
		Waste(const Waste &other);
		Waste	&operator=(const Waste &other);
		void	freeWaste();
		void	addWaste(AMateria *waste);

	private:
		Node *head;
};
