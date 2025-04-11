/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:25:06 by ptheo             #+#    #+#             */
/*   Updated: 2025/04/11 23:19:04 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &copy) {
	if (this != &copy) {
		*this = copy;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void		PmergeMe::getJacobsthal(std::vector<int> &jacob, size_t n) {
	size_t	prev = 1;
	
	while ((size_t)jacob.back() < n) {
		jacob.push_back(jacob.back() + 2 * prev);
		prev = *(jacob.end() - 2);
	}
}

void	PmergeMe::binaryInsertion(std::vector<int> &main, std::vector<int> &pend, std::vector<int> left, std::vector<int> &vec, int order) {
	size_t 	prev;
	std::vector<int> jacob;
	size_t	idx;
	
	jacob.push_back(3);
	getJacobsthal(jacob, pend.size() / order);
	std::cout << "Jacob : ";
	printIterator(jacob.begin(), jacob.end());
	if (!pend.empty()) {
		for (size_t i = 0; i < jacob.size(); i++) {
			prev = (jacob[i] == 3) ? 0 : jacob[i - 1] - 1;
			idx = jacob[i] - 1;
			if (idx > pend.size() / order)
				idx = pend.size() / order;
			while (idx > prev) {
				int l = 1;
				int r = main.size() / order;
				std::cout << "idx: " << idx << " pend: " << pend.at(idx * order - 1) << std::endl;
				while (l < r) {
					int m = (l + r) / 2;
					if (main.at(m * order - 1) > pend.at(idx * order - 1))
						r = m;
					else
						l = m + 1;
				}
				main.insert(main.begin() + (l - 1) * order, pend.begin() + idx * order - order, pend.begin() + idx * order);
				idx--;
			}
		}
		if (size_t(*(jacob.end() - 1) - 1) < pend.size() / order) {
			int i = pend.size() / order;
			while (i > *(jacob.end() - 1) - 1) {
				int l = 1;
				int r = main.size() / order;
				//std::cout << "idx: " << idx << " pend: " << pend.at(i * order - 1) << std::endl;
				while (l < r) {
					int m = (l + r) / 2;
					if (main.at(m * order - 1) > pend.at(i * order - 1))
						r = m;
					else
						l = m + 1;
				}
				main.insert(main.begin() + (l - 1) * order, pend.begin() + i * order - order, pend.begin() + i * order);
				i--;
			}
		}
	}

	vec_it s = vec.begin();
	std::vector<int> &copy = vec;
	for (size_t i = 0; i < main.size(); i++) {
		*s = main.at(i);
		s++;
	}
	if (left.size() == 1 && order == 1) {
		vec = copy;
		vec_it pos = std::lower_bound(vec.begin(), vec.end(), *left.begin());
		vec.insert(pos, *left.begin());
	} else {
		for (size_t i = 0; i < left.size(); i++) {
			*s = left.at(i);
			s++;
		}
		vec = copy;
	}
	//std::cout << "After insertion : ";
	//printIterator(vec.begin(), vec.end());
	//std::cout << std::endl;
}

void	PmergeMe::mergeInsertionSort(std::vector<int> &vec, int order) {
	int unit = vec.size() / order;
	if (unit < 2)
		return ;
	
	bool has_odd = (unit % 2 == 1);

	vec_it start = vec.begin();
	vec_it end = vec.begin() + ((order * unit) - (has_odd * order));

	for (vec_it it = start; it < end; it += order * 2) {
		if (*(it + (order - 1)) > *(it + ((order * 2) - 1))) {
			for (int i = 0; i < order; i++) {
				std::swap(*(it + i), *(it + i + order));
			}			
		}
	}

	mergeInsertionSort(vec, order * 2);

	std::vector<int> main;
	std::vector<int> pend;
	std::vector<int> left;
	
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
	std::cout << "Order : " << order << " Unit : " << unit << std::endl;
	std::cout << "Main : ";
	printIterator(main.begin(), main.end());
	std::cout << "Pend : ";
	printIterator(pend.begin(), pend.end());
	std::cout << "Left : ";
	printIterator(left.begin(), left.end());
	binaryInsertion(main, pend, left, vec, order);
}

