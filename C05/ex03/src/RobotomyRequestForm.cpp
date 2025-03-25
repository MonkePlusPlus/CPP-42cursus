/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:05:55 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/25 16:23:10 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("NoTarget") {
	std::cout << "RobotomyRequestForm without target created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target){
	std::cout << "RobotomyRequestForm with target " << target << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy), _target(copy._target){
	std::cout << "Copy of RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	if (this != &copy) {

	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned()) {
		std::cout << "RobotomyRequestForm not signed" << std::endl;
		return ;
	}
	if (executor.getGrade() > this->getToExec()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << "**Driling noises**" << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0) {
		std::cout << this->_target << " has been robotomized" << std::endl;
	} else {
		std::cout << this->_target << " has failed to be robotomized" << std::endl;
	}
}
