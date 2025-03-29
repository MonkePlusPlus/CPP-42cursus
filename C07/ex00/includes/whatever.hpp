/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:59:31 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/29 22:04:20 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template<typename T>
void	swap(T &t1, T &t2) {
	T tmp;

	tmp = t1;
	t1 = t2;
	t2 = tmp;
}

template<typename T>
T	&min(T &t1, T &t2) {
	return ((t1 > t2) ? t2 : t1);
}

template<typename T>
T	&max(T &t1, T &t2) {
	return ((t1 > t2) ? t1 : t2);
}
