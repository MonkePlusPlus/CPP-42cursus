/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:45:21 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/06 18:16:26 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int _value;
		static const int bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed & operator=(const Fixed &copy);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		Fixed	operator+(const Fixed &other);
		Fixed	operator-(const Fixed &other);
		Fixed	operator*(const Fixed &other);
		Fixed	operator/(const Fixed &other);

		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed	&operator--(void);
		Fixed	&operator++(void);

		static Fixed&			min(Fixed& n1, Fixed& n2);
		static const Fixed&		min(const Fixed& n1, const Fixed& n2);
		static Fixed&			max(Fixed& n1, Fixed& n2);
		static const Fixed&		max(const Fixed& n1, const Fixed& n2);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream&	operator<<(std::ostream& os,const Fixed& point);
