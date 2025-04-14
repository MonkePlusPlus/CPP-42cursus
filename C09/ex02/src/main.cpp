/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:24:46 by ptheo             #+#    #+#             */
/*   Updated: 2025/04/14 22:28:02 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename It>
bool	checkIsSorted(It start, It end) {
	while (start != end - 1) {
		if (*start > *(start + 1))
			return false;
		start++;
	}
	return true;
}

bool	checkNumber(std::string nb) {
	for (size_t i = 0; i < nb.size(); i++) {
		if (!isdigit(nb[i]))
			return false;
		if (atoll(nb.c_str()) > std::numeric_limits<int>::max())
			return false;
	}
	return true;
}

int	main(int ac, char *av[])
{
	PmergeMe<std::vector<int > > pmergeVec;
	PmergeMe<std::deque<int > > pmergeDeq;
	std::vector<int> vec;
	std::deque<int> deq;
	double	temps_vec;
	double	temps_deq;

	if (ac < 2)
		return (1);
	for (int i = 1; i < ac; i++) {
		if (!checkNumber(av[i])) {
			std::cout << "Invalid argument" << std::endl;
			return (1);
		}
		vec.push_back(atoi(av[i]));
		deq.push_back(atoi(av[i]));
	}
	std::cout << "Before:	";
	pmergeVec.printIterator(vec.begin(), vec.end());

	clock_t beginVec = std::clock();
	pmergeVec.mergeInsertionSort(vec, 1);
	clock_t endVec = clock();

	clock_t beginDeq = std::clock();
	pmergeDeq.mergeInsertionSort(deq, 1);
	clock_t endDeq = clock();
	
	temps_vec = double(endVec - beginVec) / CLOCKS_PER_SEC * 10000;
	temps_deq = double(endDeq - beginDeq) / CLOCKS_PER_SEC * 10000;
	
	std::cout << "After:	";
	pmergeVec.printIterator(vec.begin(), vec.end());

	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << temps_vec << "us" << std::endl;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << temps_deq << "us" << std::endl;
	
	//std::cout << "Is sorted std::vector: " << checkIsSorted(vec.begin(), vec.end()) << std::endl;
	//std::cout << "Is sorted std::deque: " << checkIsSorted(deq.begin(), deq.end()) << std::endl;
	return (0);
}
