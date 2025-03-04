/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:08:45 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/05 00:23:43 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl Harl;
    str level;
    
    while (1)
    {
        std::cout << "Enter a level (DEBUG, INFO, WARNING, ERROR) or Q to quit: ";
        if (!(std::cin >> level))
        {
            std::cout << "\nEOF detected" << std::endl;
            break;
        }
        if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR" && level != "Q")
        {
            std::cout << "Invalid input" << std::endl;
            continue;
        }
        if (level == "Q")
            break;
        Harl.complain(level);
    }
    std::cout << "Exiting..." << std::endl;
	return (0);
}
