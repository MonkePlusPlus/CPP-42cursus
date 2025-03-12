/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:39:52 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/12 11:50:58 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Contact
{
	public:
		Contact();
		int getId() {return this->id;}
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getSecret();
		std::string getPhone();
		void setId(int i);
		void setFname(std::string s);
		void setLname(std::string s);
		void setNname(std::string s);
		void setSecret(std::string s);
		void setPhone(std::string s);

	private:
		int	id;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string secret;
};