/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:54:40 by theo              #+#    #+#             */
/*   Updated: 2025/04/05 20:56:33 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char *av[])
{
	if (ac != 2) {
		std::cout << "Error: number of argument" << std::endl;
		return (1);
	}
	BitcoinExchange bitcoinExchange = BitcoinExchange();

	try {
		bitcoinExchange.createDatabase("./cpp_09/data.csv");
		bitcoinExchange.exchangePrice(av[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}