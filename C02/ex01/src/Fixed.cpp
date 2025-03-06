/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:45:19 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/06 17:47:28 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy): _value(copy._value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		this->_value = copy.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(const int i): _value(i << Fixed::bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f): _value(roundf((float)f * (1 << Fixed::bits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destrutor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

float Fixed::toFloat( void ) const {
	return (((float)this->_value) / (1 << Fixed::bits));
}

int Fixed::toInt( void ) const {
	return (this->_value >> Fixed::bits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& point) {
	float ret = point.toFloat();
	os << ret;
	return (os);
}
