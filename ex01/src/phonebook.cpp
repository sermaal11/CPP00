/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:56:58 by sergio            #+#    #+#             */
/*   Updated: 2025/07/09 12:21:14 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"
#include "../include/phonebook.hpp"

PhoneBook::PhoneBook() : _count(0) {}

void PhoneBook::add()
{
    Contact newContact;

    newContact.setFirstName(completeContact("First Name: "));
    newContact.setLastName(completeContact("Last Name: "));
    newContact.setNickname(completeContact("Nickname: "));
    newContact.setPhoneNumber(completeContact("Phone Number: "));
    newContact.setDarkestSecret(completeContact("Darkest Secret: "));

    int index = _count % 8;
    _list[index] = newContact;
    _count++;
}

void PhoneBook::search()
{
    int total;
    if (_count < 8)
        total = _count;
    else
        total = 8;
    if (_count == 0) 
    {
        std::cout << RED << "There are no saved contacts.\n" << RESET;
        return;
    } 
    else 
    {
        std::cout << CYAN
                << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << "\n"
                << RESET;
        for (int i = 0; i < total; ++i) {
            const Contact& c = _list[i];
            std::cout << std::setw(10) << i << "|"
                    << std::setw(10) << formatField(c.getFirstName()) << "|"
                    << std::setw(10) << formatField(c.getLastName()) << "|"
                    << std::setw(10) << formatField(c.getNickname()) << "\n";
        }
    }
    std::string input;
    std::cout << GREEN << "Enter index (0 - 7): " << RESET;
    std::getline(std::cin, input);
    if (!std::cin) return; // Ctrl+D
    if (input.length() != 1 || !isdigit(input[0]))
        return;
    int index = input[0] - '0';
    if (index < 0 || index >= total)
        return;
    _list[index].displayFull();
}
