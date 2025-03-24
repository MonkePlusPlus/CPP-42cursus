/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:13:42 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/24 16:58:41 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void) 
{
	Bureaucrat b1 = Bureaucrat("Bob", 150);
	Bureaucrat b2 = Bureaucrat("Jack", 1);


	try {
		b1.decrementGrade(10);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << b1.getGrade() << std::endl;
	
	try {
		b2.incrementGrade(10);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << b2.getGrade() << std::endl;

	try {
		Bureaucrat b3 = Bureaucrat("Iyan", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}