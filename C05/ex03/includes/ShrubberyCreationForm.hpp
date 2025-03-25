/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:00:40 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/25 16:14:28 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

# define ASCII_TREE "      /\\ \n     /\\*\\ \n    /\\O\\*\\ \n   /*/\\/\\/\\ \n  /\\O\\/\\*\\/\\ \n /\\*\\/\\*\\/\\/\\ \n/\\O\\/\\/*/\\/O/\\ \n      ||\n      ||\n      ||\n"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};
