/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:49:32 by theo              #+#    #+#             */
/*   Updated: 2025/04/05 20:54:37 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <fstream>

typedef std::string str;

typedef struct s_date
{
	int	year;
	int month;
	int day;
}			t_date;

typedef std::map<str, double>::iterator	base_iterator;

class BitcoinExchange
{
	private:
		std::map<str, double> _base;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange	&operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		void	exchangePrice(str path);

		void	createDatabase(str path);
		void	printDatabase();

		bool	checkDateValidity(str data);
		bool	checkValueValidity(str value);

		base_iterator findExchangeRate(str date);
		bool compareDate(t_date date, base_iterator it1, base_iterator it2);
};
