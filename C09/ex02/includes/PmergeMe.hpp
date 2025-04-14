/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:24:58 by ptheo             #+#    #+#             */
/*   Updated: 2025/04/14 22:28:51 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <ctime>
#include <cmath>

template <typename C>
class PmergeMe
{	
	
	private:
		PmergeMe(const PmergeMe &copy);
		PmergeMe	&operator=(const PmergeMe &copy);

	public:

		typedef typename C::iterator Iterator;

		PmergeMe();
		~PmergeMe();

		void	mergeInsertionSort(C &vec, int order);
		void	getJacobsthal(C &jacob, size_t n);
		void	binaryInsertion(C &main, C &pend, C left, C &vec, int order);
		void	insertionValue(C &main, C &pend, int idx, int max, int order);
		
		void	printIterator(Iterator start, Iterator end);
};

template <typename C>
PmergeMe<C>::PmergeMe() {}

template <typename C>
PmergeMe<C>::PmergeMe(const PmergeMe<C> &copy) {
	*this = copy;
}

template <typename C>
PmergeMe<C>	&PmergeMe<C>::operator=(const PmergeMe<C> &copy) {
	if (this != &copy) {
		*this = copy;
	}
	return *this;
}

template <typename C>
PmergeMe<C>::~PmergeMe() {}

template <typename C>
void	PmergeMe<C>::printIterator(Iterator start, Iterator end) {
	int	i = 0;
	bool tobig = (std::distance(start, end) > 30);
	while (start != end && i < 30) {
		std::cout << *start << " ";
		start++;
		i++;
	}
	if (tobig)
		std::cout << "[...]" << std::endl;
	else
		std::cout << std::endl;
}

template <typename C>
void		PmergeMe<C>::getJacobsthal(C &jacob, size_t n) {
	size_t	prev = 1;
	
	while ((size_t)jacob.back() < n) {
		jacob.push_back(jacob.back() + 2 * prev);
		prev = *(jacob.end() - 2);
	}
}

template <typename C>
void	PmergeMe<C>::insertionValue(C &main, C &pend, int idx, int order, int max) {
	int l = 1;
	int r = max;
	
	while (l <= r) {
		int m = (l + r) / 2;
		if (main.at(m * order - 1) == pend.at(idx * order - 1)) {
			l = m;
			break;
		}
		else if (main.at(m * order - 1) > pend.at(idx * order - 1))
			r = m - 1;
		else
			l = m + 1;
	}
	main.insert(main.begin() + (l - 1) * order, pend.begin() + idx * order - order, pend.begin() + idx * order);
}

template <typename C>
void	PmergeMe<C>::binaryInsertion(C &main, C &pend, C left, C &vec, int order) {
	size_t 	prev;
	C jacob;
	size_t	idx;
	
	jacob.push_back(3);
	getJacobsthal(jacob, pend.size() / order);
	if (!pend.empty()) {
		for (size_t i = 0; i < jacob.size(); i++) {
			prev = (jacob[i] == 3) ? 0 : jacob[i - 1] - 1;
			idx = jacob[i] - 1;
			if (idx > pend.size() / order)
				idx = pend.size() / order;
			while (idx > prev) {
				insertionValue(main, pend, idx, order, main.size() / order);
				idx--;
			}
		}
		if (size_t(*(jacob.end() - 1) - 1) < pend.size() / order) {
			int i = pend.size() / order;
			while (i > *(jacob.end() - 1) - 1) {
				insertionValue(main, pend, i, order, main.size() / order);
				i--;
			}
		}
	}

	Iterator s = vec.begin();
	C &copy = vec;
	for (size_t i = 0; i < main.size(); i++) {
		*s = main.at(i);
		s++;
	}
	if (left.size() == 1 && order == 1) {
		vec = copy;
		Iterator pos = std::lower_bound(vec.begin(), vec.end(), *left.begin());
		vec.insert(pos, *left.begin());
	} else {
		for (size_t i = 0; i < left.size(); i++) {
			*s = left.at(i);
			s++;
		}
		vec = copy;
	}
}

template <typename C>
void	PmergeMe<C>::mergeInsertionSort(C &vec, int order) {
	int unit = vec.size() / order;
	if (unit < 2)
		return ;
	
	bool has_odd = (unit % 2 == 1);

	Iterator start = vec.begin();
	Iterator end = vec.begin() + ((order * unit) - (has_odd * order));

	for (Iterator it = start; it < end; it += order * 2) {
		if (*(it + (order - 1)) > *(it + ((order * 2) - 1))) {
			for (int i = 0; i < order; i++) {
				std::swap(*(it + i), *(it + i + order));
			}			
		}
	}

	mergeInsertionSort(vec, order * 2);

	C main;
	C pend;
	C left;
	
	main.insert(main.end(), vec.begin(), vec.begin() + order);
	main.insert(main.end(), vec.begin() + order, vec.begin() + order * 2);

	int i = 2;
	while (i < unit) {
		if (i % 2 == 1)
			main.insert(main.end(), vec.begin() + order * i, vec.begin() + (order * i) + order);
		else
			pend.insert(pend.end(), vec.begin() + order * i, vec.begin() + (order * i) + order);
		i++;
	}
	if (vec.size() > size_t(order * i))
		left.insert(left.end(), vec.begin() + order * i, vec.end());
	binaryInsertion(main, pend, left, vec, order);
}