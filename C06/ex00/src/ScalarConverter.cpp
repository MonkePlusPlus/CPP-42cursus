/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:23:18 by ptheo             #+#    #+#             */
/*   Updated: 2025/03/29 19:28:41 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	*this = copy;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &copy) {
	if (this != &copy) {
		*this = copy;
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool	isChar(std::string str) {

	if (str.length() != 1 || std::isdigit(str[0]) || !std::isprint(str[0]))
		return (false);
	return (true);
}

bool	isInt(std::string str) {
	int	i = 0;

	if (str[i] == '-')
		i++;
	while (str[i]) {
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}

	if (str.length() > 11)
		return (false);
	long nb = atol(str.c_str());
	if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
		return (false);
	return (true);
}

bool	isFloat(std::string str) {
	size_t i = 0;

	if (str[i] == '-')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] != '.')
		return false;
	i++;
	while (std::isdigit(str[i]))
		i++;
	if (!(str[i] == 'f' || str[i] == 'F') || str.length() != i + 1)
		return false;

	double	nb = atof(str.c_str());
	if (nb > std::numeric_limits<float>::max() || nb < std::numeric_limits<float>::min())
		return (false);
	return (true);
}

bool	isDouble(std::string str) {
	size_t i = 0;

	if (str[i] == '-')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] != '.')
		return false;
	i++;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return false;
	return (true);
}

void	convertChar(char c) {
	if (std::isprint(c)) {
		std::cout << "char: '" << c << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " <<  std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " <<  std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void	convertInt(int i) {
	if (std::isprint(i) && i <= std::numeric_limits<char>::max() 
	&& i >= std::numeric_limits<char>::min()) {
		std::cout << "char: '" << static_cast<char>((char)i) << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " <<  std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " <<  std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void	convertFloat(float f) {
	if (std::isprint(static_cast<char>(f)) && f <= std::numeric_limits<char>::max() 
	&& f >= std::numeric_limits<char>::min()) {
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " <<  std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " <<  std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void	convertDouble(double d) {
	if (std::isprint(static_cast<char>(d)) && d <= std::numeric_limits<char>::max() 
	&& d >= std::numeric_limits<char>::min()) {
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " <<  std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	convertSpecial(std::string str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "-inf" || str == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	} else if (str == "+inf" || str == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void	ScalarConverter::convert(std::string str) {
	if (isChar(str)){
		convertChar(str[0]);
	} else if (isInt(str)) {
		convertInt(atoi(str.c_str()));
	} else if (isFloat(str)) {
		convertFloat(atof(str.c_str()));
	} else if (isDouble(str)) {
		convertDouble(atof(str.c_str()));
	} else if (str == "nan" || str == "nanf" || str == "-inf" || str == "+inf" 
			|| str == "+inff" || str == "-inff") {
		convertSpecial(str);
	}else {
		std::cout << "Enter in this type -> char | int | float | double" << std::endl;
	}
}
