/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:58:16 by ptheo             #+#    #+#             */
/*   Updated: 2025/04/05 22:20:37 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <fstream>

typedef std::string str;

class RPN
{
	private:
		std::stack<int> _vstack;
	
	public:
		RPN();
		RPN(const RPN &copy);
		RPN	&operator=(const RPN &copy);
		~RPN();

		void	printStack();

		void 	evaluateExpression(str line);
		void	calculate(char c);
};
