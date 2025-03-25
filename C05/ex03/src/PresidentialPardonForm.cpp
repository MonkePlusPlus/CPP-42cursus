/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:07:28 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/24 19:00:03 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target("NoTarget") {
	std::cout << "PresidentialPardonForm without target created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target){
	std::cout << "PresidentialPardonForm with target " << target << " created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy), _target(copy._target){
	std::cout << "Copy of PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	if (this != &copy) {

	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned()) {
		std::cout << "PresidentialPardonForm not signed" << std::endl;
		return ;
	}
	if (executor.getGrade() > this->getToExec()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
