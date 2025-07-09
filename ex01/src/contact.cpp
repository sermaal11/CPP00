/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:53:47 by sergio            #+#    #+#             */
/*   Updated: 2025/07/09 12:21:09 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"
#include "../include/phonebook.hpp"

// Setters (se pasa por referencia constante para evitar copias)
void Contact::setFirstName(const std::string& firstName) { _firstName = firstName; }
void Contact::setLastName(const std::string& lastName) { _lastName = lastName; }
void Contact::setNickname(const std::string& nickname) { _nickname = nickname; }
void Contact::setPhoneNumber(const std::string& phoneNumber) { _phoneNumber = phoneNumber; }
void Contact::setDarkestSecret(const std::string& darkestSecret) { _darkestSecret = darkestSecret; }

// Getters (const porque no modifican el objeto)
std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; } // corregido el nombre
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }

void Contact::displayFull() const
{
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone Number: " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}
