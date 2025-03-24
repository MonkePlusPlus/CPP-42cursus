/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:06:20 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/24 18:03:41 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_tosign;
		const int			_toexec;

	public:
		AForm(void);
		AForm(const AForm &copy);
		AForm(std::string name, int tosign, int toexec);
		AForm	&operator=(const AForm &copy);
		virtual ~AForm();

		class GradeTooHighException: public std::exception {
			virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception {
			virtual const char *what() const throw();
		};

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getToSign(void)	const;
		int			getToExec(void) const;

		void	beSigned(Bureaucrat &bur);

		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream&	operator<<(std::ostream& os, AForm const& form);
