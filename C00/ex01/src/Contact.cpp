/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:39:49 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/03 20:08:01 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
using namespace std;

#include "Contact.hpp"

Contact::Contact(){}

void Contact::setId(int i){
	this->id = i;
}

void Contact::setFname(string s){
	this->first_name = s;
}

void Contact::setLname(string s){
	this->last_name = s;
}

void Contact::setNname(string s){
	this->nickname = s;
}

void Contact::setSecret(string s){
	this->secret = s;
}
