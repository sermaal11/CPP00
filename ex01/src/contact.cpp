/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:53:47 by sergio            #+#    #+#             */
/*   Updated: 2025/07/09 10:13:17 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"

void Contact::setFirstName(const std::string firstName)
{
    _firstName = firstName;
}

void Contact::setLastName(const std::string lastName)
{
    _lastName = lastName;
}

void Contact::setNickname(const std::string nickname)
{
    _nickname = nickname;
}

void Contact::setPhoneNumber(const std::string phoneNumber)
{
    _phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string darkestSecret)
{
    _darkestSecret = darkestSecret;
}

std::string completeContact(std::string fieldName)
{
    std::string input;
    while (true)
    {
        std::cout << fieldName;
        std::getline(std::cin, input);
        if (!std::cin)
        {
            std::cout << RED << "\nInput interrupted. Exiting...\n" << RESET;
            exit(1);
        }
        bool hasNonSpace = false;
        for (std::size_t i = 0; i < input.length(); ++i)
        {
            if (!std::isspace(input[i]))
            {
                hasNonSpace = true;
                break;
            }
        }
        if (!hasNonSpace)
        {
            std::cout << RED << "The field cannot be empty. Please try again.\n" << RESET;
            continue;
        }
        std::size_t start = input.find_first_not_of(" \t");
        std::size_t end = input.find_last_not_of(" \t");
        input = input.substr(start, end - start + 1);
        if (fieldName == "Phone Number: ")
        {
            bool onlyDigits = true;
            for (std::size_t i = 0; i < input.length(); ++i)
            {
                if (!std::isdigit(input[i]))
                {
                    onlyDigits = false;
                    break;
                }
            }
            if (!onlyDigits)
            {
                std::cout << RED << "Phone number must contain only digits.\n" << RESET;
                continue;
            }
            if (input.length() != 9)
            {
                std::cout << RED << "Phone number must contain exactly 9 digits.\n" << RESET;
                continue;
            }
        }
        return input;
    }
}
