/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:57:37 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/24 17:37:53 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>

#include "Form.hpp"

class Form;
class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();

		class GradeTooHighException: public std::exception {
			virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception {
			virtual const char *what() const throw();
		};

		int			getGrade(void) const;
		std::string	getName(void) const;

		void	incrementGrade(int amount);
		void	decrementGrade(int amount);

		void	signForm(Form &form);

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& bur);
