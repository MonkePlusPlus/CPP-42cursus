/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:05:12 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/31 20:57:26 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _size(100){}

Span::Span(size_t n): _size(n) {
	if (n < 1)
		throw std::out_of_range("Negative number");
}

Span::Span(const Span &copy): _size(copy._size) {
	*this = copy;
}

Span	&Span::operator=(const Span &copy) {
	if (this != &copy) {
		this->_array = copy._array;
		this->_size = copy._size;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n) {
	if (this->_array.size() == this->_size)
		throw std::out_of_range("Span is full");
	this->_array.push_back(n);
}

int		Span::shortestSpan(void) {
	if (this->_size < 2)
		throw std::out_of_range("Span less than 2 numbers");
	std::vector<int> tmp = this->_array;
	std::sort(tmp.begin(), tmp.end());
	
	int	shortest = tmp[1] - tmp[0];
	for (size_t i = 2; i < tmp.size(); i++) {
		if (tmp[i] - tmp[i - 1] < shortest)
			shortest = tmp[i] - tmp[i - 1];
	}
	return shortest;
}

int		Span::longestSpan(void) {
	if (this->_size < 2)
		throw std::out_of_range("Span less than 2 numbers");
	
	std::vector<int> tmp = this->_array;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}
