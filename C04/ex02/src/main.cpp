/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:06:00 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/08 21:09:02 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	Animal *animal[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			animal[i] = new Dog();
		}
		else
		{
			animal[i] = new Cat();
		}
	}
	for (int i = 0; i < 10; i++)
	{
		animal[i]->makeSound();
	}
	for (int i = 0; i < 10; i++)
	{
		delete animal[i];
	}
	return (0);
}