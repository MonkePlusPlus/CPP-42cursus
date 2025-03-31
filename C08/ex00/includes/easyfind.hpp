/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:01:50 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/31 21:04:56 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

template<typename T>
typename T::iterator	easyfind(T &array, int n)
{
	typename T::iterator nbr = std::find(array.begin(), array.end(), n);
	if (nbr == array.end()) {
		throw std::invalid_argument("Not found in the array");
	}
	return (nbr);
}
