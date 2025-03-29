/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:07:36 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/29 22:17:47 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstddef>

template <typename T, typename F>
void	iter(T *array, size_t len_array, F f) {
	for (size_t i = 0; i < len_array; i++) {
		f(array[i]);
	}
}

template <typename T>
void	printItem(T &t) {
	std::cout << t << std::endl;
}
