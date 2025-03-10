/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:39:49 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/10 16:39:25 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Contact.hpp"

Contact::Contact(){}

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
