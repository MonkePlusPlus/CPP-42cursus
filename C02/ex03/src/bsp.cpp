/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:28:19 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/18 18:08:18 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed	area(Point a, Point b, Point c) {
	return (b.getX() - a.getX()) * (c.getY() - a.getY()) - 
		   (b.getY() - a.getY()) * (c.getX() - a.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed d1, d2, d3;

    d1 = area(a, b, point);
    d2 = area(b, c, point);
    d3 = area(c, a, point);

	bool has_neg, has_pos;

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(has_neg && has_pos);	
}