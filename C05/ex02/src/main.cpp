/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:13:42 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/25 16:09:13 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int		main(void) 
{
	Bureaucrat b1 = Bureaucrat("Bob", 150);
	Bureaucrat b2 = Bureaucrat("Jack", 1);

	RobotomyRequestForm rf = RobotomyRequestForm("robot");
	PresidentialPardonForm pf = PresidentialPardonForm("president");
	ShrubberyCreationForm sf = ShrubberyCreationForm("berry");

	std::cout << std::endl << "ROBOTOMY FORM TEST" << std::endl << std::endl;
	b1.executeForm(rf);
	b1.signForm(rf);

	b2.signForm(rf);
	b2.executeForm(rf);


	std::cout << std::endl << "SHRUBBERY FORM TEST" << std::endl << std::endl;
	b1.executeForm(sf);
	b1.signForm(sf);

	b2.signForm(sf);
	b2.executeForm(sf);
	
	std::cout << std::endl << "PRESIDENTIAL FORM TEST" << std::endl << std::endl;
	b1.executeForm(pf);
	b1.signForm(pf);

	b2.signForm(pf);
	b2.executeForm(pf);

	std::cout << std::endl;
	
	return (0);
}