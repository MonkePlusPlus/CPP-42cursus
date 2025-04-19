/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:49:23 by theo              #+#    #+#             */
/*   Updated: 2025/04/19 19:07:44 by ptheo            ###   ########.fr       */
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
	std::ifstream file (path.c_str());
	if (!file.is_open()) {
		throw std::invalid_argument("Error: could not open file");
	}
	
	getline(file, line);
	while (getline(file, line)) {
		if (line.find(",") == line.npos)
			throw std::invalid_argument("Error: database is not in form date,exchange");
		str date = line.substr(0, line.find(","));
		str value = line.substr(line.find(",") + 1, line.length());
		if (!checkDateValidity(date) || !checkValueValidity(value, true) || value.length() < 1)
			throw std::invalid_argument("Error: invalid date in database");
		double exchange = atof(value.c_str());
		this->_base[date] = exchange; 
	}
}

void	BitcoinExchange::printDatabase() {
	std::map<str, double>::iterator it = _base.begin();
	while (it != _base.end()) {
		std::cout << it->first << " : " << it->second << std::endl;
		it++;
	}
}

bool	allNumber(str nbr) {
	str::iterator it = nbr.begin();
	while (it != nbr.end()) {
		if (*it < 48 || *it > 57) {
			return (false);
		}
		it++;
	}
	return (true);
}

bool	checkMonthDay(int year, int month, int day) {
	if (month < 0 || month > 12 || day < 0 || day > 31)
		return (false);
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0 && day > 29) 
		|| (year % 4 != 0 && day > 28)
		|| (year % 4 == 0 && year % 100 == 0 && year % 400 != 0 && day > 28))
			return (false);
		return (true);
	}
	if (month < 8 && ((month % 2 == 0 && day > 30) || (month % 2 == 1 && day > 31))) {
		return (false);
	}
	if (month > 7 && ((month % 2 == 1 && day > 30) || (month % 2 == 0 && day > 31))) {
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::checkDateValidity(str date) {
	str	year;
	str	month;
	str	day;

	if (std::count(date.begin(), date.end(), '-') != 2) {
		return (false);
	}
	year = date.substr(0, date.find("-"));
	month = date.substr(date.find("-") + 1, date.find_last_of('-') - date.find("-") - 1);
	day = date.substr(date.find_last_of("-") + 1);
	if (!(allNumber(year) && allNumber(month) && allNumber(day))
		|| month.size() != 2 || day.size() != 2
		|| !checkMonthDay(atoi(year.c_str()), atoi(month.c_str()), atoi(day.c_str()))) {
		std::cout << "Error: bad input => " << date << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::checkValueValidity(str value, bool data) {
	int	check = std::count(value.begin(), value.end(), '.');

	if (value[0] == '-'){
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (check > 1 || (check == 0 && !allNumber(value))) {
		std::cout << "Error: bad input => " << value << std::endl;
		return (false);
	}
	if (check == 1) {
		if (!allNumber(value.substr(0, value.find('.')))
		||  !allNumber(value.substr(value.find('.') + 1, value.size()))) {
			std::cout << "Error: bad input => " << value << std::endl;
			return (false);
		}
	}
	
	double	nbr = atof(value.c_str());
	if (nbr < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (nbr > 1000 && !data) {
		std::cout << "Error: too large number." << std::endl;
		return (false);
	}
	return (true);
}

t_date	getDate(str date) {
	str year, month, day;
	year = date.substr(0, date.find("-"));
	month = date.substr(date.find("-") + 1, date.find_last_of('-') - date.find("-") - 1);
	day = date.substr(date.find_last_of("-") + 1);

	t_date d;

	d.year = atoi(year.c_str());
	d.month = atoi(month.c_str());
	d.day = atoi(day.c_str());
	return (d);
}

bool	checkInfDate(t_date date, t_date other) {
	if (other.year < date.year)
		return (true);
	if (other.month < date.month && other.year == date.year)
		return (true);
	if (other.day < date.day && other.year == date.year && other.month == date.month)
		return (true);
	if (other.day == date.day && other.year == date.year && other.month == date.month)
		return (true);
	return (false);
}

bool	BitcoinExchange::compareDate(t_date date, base_iterator it1, base_iterator it2) {
	t_date other = getDate(it2->first);
	if (it1 == _base.end()) {
		return (checkInfDate(date, other));
	}
	t_date closer = getDate(it1->first);
	if (!checkInfDate(date, other))
		return (false);
	
	if (date.year - closer.year > date.year - other.year)
		return (true);
	if (date.month - closer.month > date.month - other.month && closer.year == other.year)
		return (true);
	if (date.day - closer.day > date.day - other.day && closer.year == other.year
		&& closer.month == other.month)
		return (true);
	return (false);
}

base_iterator BitcoinExchange::findExchangeRate(str date) {
	base_iterator it = this->_base.begin();
	base_iterator closer = _base.end();

	t_date d = getDate(date);
	while (it != _base.end()) {
		if (compareDate(d, closer, it)) {
			closer = it;
		}
		it++;
	}
	return (closer);
}

void	BitcoinExchange::exchangePrice(str path) {
	str line;
	str	date;
	str value;
	std::ifstream file (path.c_str());
	if (!file.is_open()) {
		throw std::invalid_argument("Error: could not open file");
	}
	if (_base.size() < 1) {
		return ;
	}
	getline(file, line);
	if (line != "date | value") {
		return ;
	}
	while (getline(file, line)) {
		if (std::count(line.begin(), line.end(), '|') != 1) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, line.find("|") - 1);
		value = line.substr(line.find("|") + 2);
		if (!checkDateValidity(date) || !checkValueValidity(value, false))
			continue;
		double v_value = atof(value.c_str());
		base_iterator it = findExchangeRate(date);
		if (it != _base.end()) {
			std::cout << date << " => " << value << " = " << it->second * v_value << std::endl;
		} else {
			std::cout << "Error: No suitable data found" << std::endl; 
		}
	}
}
