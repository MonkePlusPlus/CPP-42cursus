/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:39:52 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/03 21:03:08 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Contact
{
	public:
		Contact();
		int getId() {return this->id;}
		std::string getFirstName() {return this->first_name;}
		std::string getLastName() {return this->last_name;}
		std::string getNickname() {return this->nickname;}
		std::string getSecret() {return this->secret;}
		void setId(int i);
		void setFname(std::string s);
		void setLname(std::string s);
		void setNname(std::string s);
		void setSecret(std::string s);

	private:
		int	id;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string secret;
};