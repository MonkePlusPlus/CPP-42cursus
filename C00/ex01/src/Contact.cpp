/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:39:49 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/12 11:55:48 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Contact.hpp"

Contact::Contact(){}

int Contact::getId() {
	return this->id;
}

std::string Contact::getFirstName() {
	return this->first_name;
}

std::string Contact::getLastName() {
	return this->last_name;
}

std::string Contact::getNickname() {
	return this->nickname;
}

std::string Contact::getSecret() {
	return this->secret;
}

std::string Contact::getPhone() {
	return (this->phone_number);
}

void Contact::setId(int i){
	this->id = i;
}

void Contact::setFname(std::string s){
	this->first_name = s;
}

void Contact::setLname(std::string s){
	this->last_name = s;
}

void Contact::setNname(std::string s){
	this->nickname = s;
}

void Contact::setSecret(std::string s){
	this->secret = s;
}

void Contact::setPhone(std::string s) {
	this->phone_number = s;
}
