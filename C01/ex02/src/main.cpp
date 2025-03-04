/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:22:58 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/04 16:35:09 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

typedef std::string str;

int main( void ){
	str string = "HI THIS IS BRAIN";
	str *stringPTR = &string;
	str &stringREF = string;

	std::cout << "The memory address of the string variable : " << &string << std::endl;
	std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF : " << &stringREF << std::endl;

	std::cout << "The value of the string variable : " << string <<std::endl;
	std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF : " << stringREF << std::endl;
	return (0);
}
