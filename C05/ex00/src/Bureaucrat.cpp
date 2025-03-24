/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:57:40 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/24 16:56:26 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	checkGrade(int grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(void): _name("NoName"), _grade(150) {
	std::cout << "Bureaucrat without name created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	checkGrade(grade);
	std::cout << "Bureaucrat " << name << " created with grade : " << grade << std::endl;
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade) {
	std::cout << "Copy of Bureaucrat" << copy._name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy) {
		this->_grade = copy._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Exception: Grade too Low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Exception: Grade too High";
}

int		Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

void	Bureaucrat::incrementGrade(int amount) {
	checkGrade(this->_grade - amount);
	this->_grade -= amount;
}

void	Bureaucrat::decrementGrade(int amount) {
	checkGrade(this->_grade + amount);
	this->_grade += amount;
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& bur) {
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return (os); 
}
