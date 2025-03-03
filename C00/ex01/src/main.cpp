/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:43:38 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/03 20:22:51 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	std::string line;
	PhoneBook phonebook = PhoneBook();

	std::cout << "[Enter the command]" << std::endl;
	std::getline(std::cin, line);
	while (line != "EXIT" && !std::cin.eof()){
		if (line == "ADD"){
			std::cout << std::endl;
			phonebook.addContact();
		}
		else if (line == "SEARCH"){
			std::cout << std::endl;
			phonebook.searchContact();
		}
		else {
			std::cout << "[Command invalid]" << std::endl;
			std::cout << std::endl;
		}
		std::cout << "[Enter the command]" << std::endl;
		std::getline(std::cin, line);
	}
	std::cout << "[Exit system]" << std::endl;
	return (0);
}