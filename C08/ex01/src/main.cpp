/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:08:59 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/31 20:59:58 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	std::vector<int> v;

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		int n = rand() % 100;
		v.push_back(n);
		std::cout << "v[" << i << "] : " << n << std::endl;
	}
	Span s = Span(10);
	
	try {
		s.addNumber(v.begin(), v.end());
		
		std::cout << "Longest Span : " << s.longestSpan() << std::endl;
		std::cout << "Shortest Span : " << s.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
