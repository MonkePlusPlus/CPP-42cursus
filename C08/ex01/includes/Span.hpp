/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:58:19 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/31 20:54:23 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <ctime>

class Span
{
	private:
		std::vector<int>	_array;
		size_t				_size;

	public:
		Span(void);
		Span(size_t	n);
		Span(const Span &copy);
		Span	&operator=(const Span &copy);
		~Span();

		void	addNumber(int n);

		int		shortestSpan(void);
		int		longestSpan(void);

		template <typename It>
		void	addNumber(It begin, It end) {
			if (this->_array.size() + std::distance(begin, end) > this->_size)
				throw std::out_of_range("Range too big");
			this->_array.insert(this->_array.end(), begin, end);
		}
};
