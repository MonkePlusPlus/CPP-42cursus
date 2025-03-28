/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:31:39 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/28 19:44:45 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base	*generate(void) {
	srand(time(NULL));
	switch (rand() % 3) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return NULL;
	}
}

void	identify(Base* p){
	if (dynamic_cast<A*>(p)) {
		std::cout << "Identify as A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "Identify as B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "Identify as C" << std::endl;
	}
}

void	identify(Base& p){
	if (dynamic_cast<A*>(&p)) {
		std::cout << "Identify as A" << std::endl;
	} else if (dynamic_cast<B*>(&p)) {
		std::cout << "Identify as B" << std::endl;
	} else if (dynamic_cast<C*>(&p)) {
		std::cout << "Identify as C" << std::endl;
	}
}

int	main() {
	Base *base = generate();
	
	identify(base);
	identify(*base);
	delete base;
	return (0);
}