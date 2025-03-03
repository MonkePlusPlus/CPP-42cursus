/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:39:51 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/03 20:07:53 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		void addContact();
		void searchContact();

 	private:
		Contact list[8];
		int	nb_contact;
};