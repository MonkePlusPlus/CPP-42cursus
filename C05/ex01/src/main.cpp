/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:13:42 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/24 17:52:06 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void) 
{
	Bureaucrat b1 = Bureaucrat("Bob", 150);
	Bureaucrat b2 = Bureaucrat("Jack", 1);

	Form f1 = Form("testForm", 50, 50);

	b1.signForm(f1);
	b2.signForm(f1);

	try {
		Form f2 = Form("cantForm", 151, 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}