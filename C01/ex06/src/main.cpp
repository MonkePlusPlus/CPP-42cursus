/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:08:45 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/05 00:24:40 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char *av[]) {
    Harl Harl;
    str level;
    
    if (ac != 2){
        std::cout << "Error number argument" << std::endl;
        return (-1);
    }
    level = av[1];
    Harl.complain(level);
    return (0);
}
