/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:24:58 by ptheo             #+#    #+#             */
/*   Updated: 2025/04/11 22:29:33 by ptheo            ###   ########.fr       */
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

typedef std::vector<int>::iterator vec_it;
typedef std::deque<int>::iterator deq_it;

class PmergeMe
{	
	private:
		PmergeMe(const PmergeMe &copy);
		PmergeMe	&operator=(const PmergeMe &copy);

	public:
		PmergeMe();
		~PmergeMe();

		void	mergeInsertionSort(std::vector<int> &vec, int order);
		void	getJacobsthal(std::vector<int> &jacob, size_t n);
		void	binaryInsertion(std::vector<int> &main, std::vector<int> &pend, std::vector<int> left, std::vector<int> &vec, int order);

		
		template<typename It>
		void	printIterator(It start, It end) {
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
};
