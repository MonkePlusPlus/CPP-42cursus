/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:01:40 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/31 21:06:21 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> v;

	v.push_back(2);
	v.push_back(4);
	v.push_back(1);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	std::cout << "Find 4 : " << *easyfind(v, 4) << std::endl;
	return (0);
}
