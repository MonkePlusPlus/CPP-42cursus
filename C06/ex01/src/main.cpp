/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:10:48 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/28 19:43:12 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data *data = new Data();
	uintptr_t ptr;

	data->value1 = 1;
	data->value2 = 0;
	try {
		ptr = Serializer::serialize(data);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Data *tmp = Serializer::deserialize(ptr);
	std::cout << "Data ptr: " << data << " -> " << data->value1 << " | " << data->value2 << std::endl;
	std::cout << "ptr: " << ptr << std::endl;
	if (tmp != NULL)
		std::cout << "Other ptr: " << tmp << " -> " << tmp->value1 << " | " << tmp->value2 << std::endl;
	delete data;
	return (0);
}