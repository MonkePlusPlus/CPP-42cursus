/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:25:47 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/29 22:47:35 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void): _array(new T[0]()), _size(0) {}

template <typename T>
Array<T>::Array(size_t n): _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &copy): _array(new T[copy._size]()), _size(copy._size){
	for (size_t	i = 0; i < copy._size; i++) {
		this->_array[i] = copy._array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete [] this->_array;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &copy) {
	if (this != &copy) {
		delete [] this->_array;
		this->_array = new T[copy._size]();
		for (size_t i = 0; i < copy._size; i++) {
			this->_array[i] = copy._array[i];
		}
		this->_size = copy._size;
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](size_t i) {
	if (i >= this->_size || i < 0) {
		throw std::out_of_range("Index out of Bounds");
	}
	return (this->_array[i]);
}

template <typename T>
size_t	Array<T>::size(void) {
	return (this->_size);
}
