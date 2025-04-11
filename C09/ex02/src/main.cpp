/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:24:46 by ptheo             #+#    #+#             */
/*   Updated: 2025/04/11 23:01:39 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
	PmergeMe pmerge;
	std::vector<int> vec;
	std::deque<int> deq;
	double	temps_vec;

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
	pmerge.printIterator(vec.begin(), vec.end());

	clock_t beginVec = std::clock();
	pmerge.mergeInsertionSort(vec, 1);
	clock_t endVec = clock();
	
	temps_vec = double(endVec - beginVec) / CLOCKS_PER_SEC * 1000;
	std::cout << "After:	";
	pmerge.printIterator(vec.begin(), vec.end());

	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << temps_vec << "us" << std::endl;
	return (0);
}
