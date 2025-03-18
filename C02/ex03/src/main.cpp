/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:45:22 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/18 18:11:26 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
    Point a = Point(0.0, 0.0); 
    Point b = Point(10.0, 0.0); 
    Point c = Point(0.0, 10.0);
    Point p = Point(1.0, 1.0);
    Point p2 = Point(4.51, 5.89);

    if (bsp(a, b, c, p)) {
        std::cout << "inside" << std::endl;
    } else {
        std::cout << "outside" << std::endl;
    }
    if (bsp(a, b, c, p2)) {
        std::cout << "inside" << std::endl;
    } else {
        std::cout << "outside" << std::endl;
    }
	return (0);
}