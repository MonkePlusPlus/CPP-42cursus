/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:08:45 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/31 21:18:19 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iterator>
#include <stack>
#include <algorithm>
#include <ctime>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &copy): std::stack<T>(copy) {}
		MutantStack	&operator=(const MutantStack &copy) {
			if (this != &copy) {
				std::stack<T>::operator=(copy);
			}
			return (*this);
		}
		~MutantStack() {}

		iterator begin() {return (this->c.begin());}
		iterator end() {return (this->c.end());}
		reverse_iterator rbegin() {return (this->c.rbegin());}
		reverse_iterator rend() {return (this->c.rend());}

		const_iterator cbegin() const {return (this->c.begin());}
		const_iterator cend() const {return (this->c.end());}
		const_reverse_iterator rbegin() const {return (this->c.rbegin());}
		const_reverse_iterator rend() const {return (this->c.rend());}
};
