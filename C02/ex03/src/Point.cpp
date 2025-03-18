/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:28:28 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/18 17:34:33 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0){}

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y)) {}

Point::~Point() {}

Point::Point(const Point &copy): _x(copy._x), _y(copy._y) {}

Point&	Point::operator=(const Point &copy) {
	if (this != &copy) {
		this->_x = copy._x;
		this->_y = copy._y;
	}
	return (*this);
}

Fixed 	Point::getX() const {
	return (this->_x);
}

Fixed	Point::getY() const {
	return (this->_y);
}