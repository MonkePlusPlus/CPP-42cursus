/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:49:23 by theo              #+#    #+#             */
/*   Updated: 2025/04/04 18:23:20 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy) {
		*this = copy;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::createDatabase(str path) {
	str line;
	std::ifstream file (path);
	if (!file.is_open()) {
		throw std::invalid_argument("File doesn't exit");
	}
	
	getline(file, line);
	while (getline(file, line)) {
		if (line.find(",") == line.end())
			throw std::invalid_argument("Database is not in form date , exchange");
		str date = line.substr(0, line.find(","));
		double exchange = atof(line.substr(line.find(",") + 1, line.length()));
		this->_base[date] = exchange; 
	}
}
