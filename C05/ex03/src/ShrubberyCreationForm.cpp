/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:04:32 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/25 16:54:43 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), _target("NoTarget") {
	std::cout << "ShrubberyCreationForm without target created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target){
	std::cout << "ShrubberyCreationForm with target " << target << " created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy), _target(copy._target){
	std::cout << "Copy of ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	if (this != &copy) {
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned()) {
		std::cout << "ShrubberyCreationForm not signed" << std::endl;
		return ;
	}
	if (executor.getGrade() > this->getToExec()) {
		throw AForm::GradeTooLowException();
	}
	std::ofstream file (((std::string)this->_target).insert(this->_target.length(), "_shrubbery").c_str());
	if (!file.is_open() || file.fail())
		return ;
	file << ASCII_TREE;
	file.close();
}
