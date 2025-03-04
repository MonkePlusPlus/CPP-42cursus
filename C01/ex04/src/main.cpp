/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:50:15 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/04 21:05:34 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream> 
#include <string>

typedef std::string str;

int main(int ac, char *av[])
{
	if (ac != 4){
		std::cout << "Error number argument\n";
		return (-1);
	}

	str file_name = av[1];
	str replace_word = av[2];
	str new_word = av[3];

	if (file_name.empty() || replace_word.empty() || new_word.empty()){
		std::cout << "Error argument\n";
		return (-1);
	}
		
	std::ifstream o_file (av[1]);
	if (!o_file.is_open()){
		std::cout << "File doesn't exist\n";
		o_file.close();
		return (0);
	}
	str name = av[1];
	std::ofstream r_file (name.insert(name.length(), ".replace").c_str());
	
	str line;
	size_t len_rword = replace_word.length();
	size_t pos;
	size_t current_pos = 0;

	while (std::getline(o_file, line)){
		while ((pos = line.find(replace_word)) != std::string::npos)
		{
			for (size_t i = current_pos; i < pos; i++){
				r_file << line[i];
			}
			current_pos = pos;
			line.erase(pos, len_rword);
			r_file << av[3];
		}
		r_file << line.erase(0, current_pos) << std::endl;
		current_pos = 0;
	}
	o_file.close();
	r_file.close();
	return (0);
}