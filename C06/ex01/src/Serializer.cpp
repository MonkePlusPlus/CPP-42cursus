/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:03:58 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/28 19:24:49 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &copy) {
	*this = copy;
}

Serializer &Serializer::operator=(const Serializer &copy) {
	if (this != &copy){
		*this = copy;
	}
	return *this;
}

Serializer::~Serializer() {}

const char *Serializer::NullPointerExeption::what() const throw() {
	return ("Null pointer Exeption");
}

uintptr_t Serializer::serialize(Data* ptr) {
	if (ptr == NULL)
		throw NullPointerExeption();
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

