/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:24:08 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/25 17:00:13 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &copy);
		Intern	&operator=(const Intern &copy);
		~Intern();

		AForm *makeForm(std::string name, std::string target);

		class InvalidFormException: public std::exception {
			virtual const char *what() const throw();
		};
};
