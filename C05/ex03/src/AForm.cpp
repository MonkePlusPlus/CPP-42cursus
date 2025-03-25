/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:06:15 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/24 17:53:24 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

void	checkFormGrade(int grade) {
	if (grade < 1) {
		throw AForm::GradeTooHighException();
	}
	if (grade > 150) {
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(void): _name("NoName"), _signed(false), _tosign(150), _toexec(150) {
	std::cout << "AForm without name created" << std::endl;
}

AForm::AForm(const AForm &copy): _name(copy._name), _signed(copy._signed), _tosign(copy._tosign), _toexec(copy._toexec) {
	std::cout << "Copy of form created" << std::endl;
}

AForm::AForm(std::string name, int tosign, int toexec): _name(name), _signed(false), _tosign(tosign), _toexec(toexec) {
	checkFormGrade(tosign);
	checkFormGrade(toexec);
	std::cout << "AForm " << name << " created" << std::endl;
}

AForm	&AForm::operator=(const AForm &copy) {
	if (this != &copy) {
		this->_signed = copy._signed;
	}
	return (*this);
}

AForm::~AForm() {
	std::cout << "AForm " << this->_name << " destroyed" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too High";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too Low";
}

std::string	AForm::getName(void) const {
	return (this->_name);
}

bool		AForm::getSigned(void) const {
	return (this->_signed);
}

int			AForm::getToSign(void)	const {
	return (this->_tosign);
}

int			AForm::getToExec(void) const {
	return (this->_toexec);
}

void	AForm::beSigned(Bureaucrat &bur) {
	if (bur.getGrade() > this->_tosign) {
		throw GradeTooLowException();
	}
	this->_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const { 
	if (!this->_signed) {
		std::cout << "The Form " << this->_name << " is not signed" << std::endl;
		return ;
	}
	if (this->_toexec < executor.getGrade()) {
		throw GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& os, AForm const& form) {
	os << form.getName() << " is signed : " << form.getSigned();
	return (os);
}
