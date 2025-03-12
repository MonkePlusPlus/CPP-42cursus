/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:39:47 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/12 11:51:03 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	this->nb_contact = 0;
}

void PhoneBook::addContact() {
	Contact contact = Contact();
	std::string line;

	std::cout << "[Enter the First Name of the contact]" << std::endl;
	std::getline(std::cin, line);
	while (line.empty() && !std::cin.eof()){
		std::cout << "[First Name can't be empty]" << std::endl;
		getline(std::cin, line);
	}
	contact.setFname(line);
	std::cout << std::endl;

	std::cout << "[Enter the Last Name of the contact]" << std::endl;
	getline(std::cin, line);
	while (line.empty() && !std::cin.eof()){
		std::cout << "[Last Name can't be empty]" << std::endl;
		getline(std::cin, line);
	}
	contact.setLname(line);
	std::cout << std::endl;

	std::cout << "[Enter the Nickname of the contact]" << std::endl;
	getline(std::cin, line);
	while (line.empty() && !std::cin.eof()){
		std::cout << "[Nickame can't be empty]" << std::endl;
		getline(std::cin, line);
	}
	contact.setNname(line);
	std::cout << std::endl;

	std::cout << "[Enter the phone number of the contact]" << std::endl;
	std::getline(std::cin, line);
	while (line.empty() && !std::cin.eof()){
		std::cout << "[Phone number can't be empty]" << std::endl;
		std::getline(std::cin, line);
	}
	contact.setPhone(line);
	std::cout << std::endl;

	std::cout << "[Enter the darkest secret of the contact]" << std::endl;
	std::getline(std::cin, line);
	while (line.empty() && !std::cin.eof()){
		std::cout << "[Darkest secret can't be empty]" << std::endl;
		std::getline(std::cin, line);
	}
	contact.setSecret(line);
	std::cout << std::endl;

	if (this->nb_contact == 8) { 
		for (int i = 0; i < 7; i++){
			this->list[i] = this->list[i + 1];
			this->list[i].setId(i);
		}
		contact.setId(8);
		this->list[7] = contact;
	} else {
		contact.setId(nb_contact);
		this->list[nb_contact] = contact;
		this->nb_contact++;
	}
	std::cout << "[Contact " + contact.getFirstName() + " added]" << std::endl;
	std::cout << std::endl;
}

void display_contact(Contact contact){
	std::cout << "ID : " << contact.getId() << std::endl;
	std::cout << "Fist Name : " << contact.getFirstName() << std::endl;
	std::cout << "Last Name : " << contact.getLastName() << std::endl;
	std::cout << "Nickname : " << contact.getNickname() << std::endl;
	std::cout << "Phone Number : " << contact.getPhone() << std::endl;
	std::cout << "Darkest Secret : " << contact.getSecret() << std::endl;
	std::cout << std::endl;
}

std::string get_space(int n){
	std::string space = "";

	for (int i = 0; i < n; i++){
		space += " ";
	}
	return (space);
}

void cut_word(std::string word){
	if (word.length() > 10) {
		std::cout << word.substr(0, 9) << ".";
	} else {
		std::cout << get_space(10 - word.length()) << word;
	}
}

void print_contact(Contact list[8], int nb) {
	std::cout << "|";
	cut_word("ID");
	std::cout << "|";
	cut_word("First Name");
	std::cout << "|";	
	cut_word("Last Name");
	std::cout << "|";
	cut_word("Nickname");
	std::cout << "|";
	std::cout << std::endl;
	for (int i = 0; i < nb; i++){
		std::cout << "|" << get_space(9) << i;
		std::cout << "|";
		cut_word(list[i].getFirstName());
		std::cout << "|";
		cut_word(list[i].getLastName());
		std::cout << "|";
		cut_word(list[i].getNickname());
		std::cout << "|";
		std::cout << std::endl;
	}
}

bool is_numeric(std::string string){
	for (size_t i = 0; i < string.length(); i++) {
		if (!isdigit(string[i])){
			return (false);
		}
	}
	return (true);
}

void PhoneBook::searchContact() {
	std::string line;
	int id;

	print_contact(this->list, this->nb_contact);
	if (this->nb_contact < 1) {
		std::cout << "[No contact]" << std::endl << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "[Enter the ID of the contact you want to display]" << std::endl;
	std::getline(std::cin, line);
	id = atoi(line.c_str());
	while ((id < 0 || id >= this->nb_contact || line.empty() || !is_numeric(line)) && !std::cin.eof()) {
		std::cout << "[Enter a correct ID of the contact you want to display]" << std::endl;
		std::getline(std::cin, line);
		id = atoi(line.c_str());
	}
	std::cout << std::endl;
	display_contact(this->list[id]);
}
