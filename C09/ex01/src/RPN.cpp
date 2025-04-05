/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:58:13 by ptheo             #+#    #+#             */
/*   Updated: 2025/04/05 22:20:27 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy) {
	*this = copy;
}

RPN	&RPN::operator=(const RPN &copy) {
	if (this != &copy) {
		*this = copy;
	}
	return *this;
}

RPN::~RPN() {}

void	RPN::printStack() {
	while (!_vstack.empty()) {
		std::cout << _vstack.top() << " ";
		_vstack.pop();
	}
	std::cout << std::endl;
}

void	RPN::calculate(char c) {
	int	n1 = _vstack.top();
	_vstack.pop();
	int	n2 = _vstack.top();
	_vstack.pop();

	switch (c) {
		case '+': _vstack.push(n1 + n2); break;
		case '-': _vstack.push(n1 - n2); break; 
		case '*': _vstack.push(n1 * n2); break;
		case '/': _vstack.push(n1 / n2); break;
	}
}

void	RPN::evaluateExpression(str line) {
	for (size_t i = 0; i < line.size(); i++) {

		if (line[i] == ' ')
			continue;
		if (isdigit(line[i])){
			_vstack.push(line[i] - '0');
			if (line[i + 1] != ' ' || line[i + 1] != '\0')
				throw std::invalid_argument("Error");
		}
		if (line[i] == '*' || line[i] == '+' || line[i] == '/' || line[i] == '-')
			calculate(line[i]);
		i++;
	}
	if (_vstack.size() != 1) {
		throw std::invalid_argument("Error");
	}
	std::cout << _vstack.top() << std::endl;
}

