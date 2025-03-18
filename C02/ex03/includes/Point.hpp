/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:28:56 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/18 17:33:55 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		Fixed _x;
		Fixed _y;

	public:
		Point();
		Point(const float x, const float y);
		~Point();
		Point(const Point &copy);
		Point&	operator=(const Point &copy);

		Fixed 	getX() const;
		Fixed	getY() const;
};
