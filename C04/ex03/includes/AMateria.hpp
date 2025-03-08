/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:18:41 by theo              #+#    #+#             */
/*   Updated: 2025/03/08 22:32:03 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		AMateria(std::string const & type);
		virtual ~AMateria();
		
		std::string const & getType() const; //Returns the materia type
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};