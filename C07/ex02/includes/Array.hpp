/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:19:19 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/29 22:42:48 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstddef>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(const Array &copy);
		Array(size_t n);
		Array	&operator=(const Array &copy);
		~Array();
		T	&operator[](size_t i);
		
		size_t	size(void);

	private:
		T		*_array;
		size_t	_size;
};

#include "Array.tpp"