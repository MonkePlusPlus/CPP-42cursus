/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:06:15 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/24 17:50:36 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void	checkFormGrade(int grade) {
	if (grade < 1) {
		throw Form::GradeTooHighException();
	}
	if (grade > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::Form(void): _name("NoName"), _signed(false), _tosign(150), _toexec(150) {
	std::cout << "Form without name created" << std::endl;
}

Form::Form(const Form &copy): _name(copy._name), _signed(copy._signed), _tosign(copy._tosign), _toexec(copy._toexec) {
	std::cout << "Copy of form created" << std::endl;
}

Form::Form(std::string name, int tosign, int toexec): _name(name), _signed(false), _tosign(tosign), _toexec(toexec) {
	checkFormGrade(tosign);
	checkFormGrade(toexec);
	std::cout << "Form " << name << " created" << std::endl;
}

Form	&Form::operator=(const Form &copy) {
	if (this != &copy) {
		this->_signed = copy._signed;
	}
	return (*this);
}

Form::~Form() {
	std::cout << "Form " << this->_name << " destroyed" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too High";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too Low";
}

std::string	Form::getName(void) const {
	return (this->_name);
}

bool		Form::getSigned(void) const {
	return (this->_signed);
}

int			Form::getToSign(void)	const {
	return (this->_tosign);
}

int			Form::getToExec(void) const {
	return (this->_toexec);
}

void	Form::beSigned(Bureaucrat &bur) {
	if (bur.getGrade() > this->_tosign) {
		throw GradeTooLowException();
	}
	this->_signed = true;
}

std::ostream&	operator<<(std::ostream& os, Form const& form) {
	os << form.getName() << " is signed : " << form.getSigned();
	return (os);
}
