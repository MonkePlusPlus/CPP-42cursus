/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:24:03 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/25 17:01:16 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <map>

Intern::Intern(void) {
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &copy) {
	std::cout << "Intern created" << std::endl;
	*this = copy;
}

Intern	&Intern::operator=(const Intern &copy) {
	if (this != &copy){
	}
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern destroyed" << std::endl;
}

const char *Intern::InvalidFormException::what() const throw() {
	return "Invalid Form found";
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::map<std::string, int> dico;
	dico["robotomy request"] = 0;
	dico["presidential pardon"] = 1;
	dico["shrubbery creation"] = 2;

	if (dico.find(name) == dico.end()){
		throw InvalidFormException();
	}
	switch (dico[name])
	{
		case 0 : return new RobotomyRequestForm(target);
		case 1 : return new PresidentialPardonForm(target);
		case 2 : return new ShrubberyCreationForm(target);

		default: std::cout << "No form with this name" << std::endl; return NULL;
	}
}
