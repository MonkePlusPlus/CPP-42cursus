/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:58:25 by ptheo             #+#    #+#             */
/*   Updated: 2025/04/07 16:07:42 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char *av[])
{
	if (ac != 2) {
		std::cout << "Error" << std::endl;
		return (1);
	}
	RPN rpn;

	//rpn.printStack();
	try {
		rpn.evaluateExpression(av[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
