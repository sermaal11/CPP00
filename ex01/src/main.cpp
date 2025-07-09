/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:33:06 by sergio            #+#    #+#             */
/*   Updated: 2025/07/09 12:18:51 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"
#include "../include/phonebook.hpp"

int main (int argc, char **argv)
{
    (void) argv;
    std::string input;
    PhoneBook phoneBook;

    if (argc == 1)
    {
        initPhoneBook();

        while (true)
        {
            std::cout << GREEN << "WAITING COMMAND:\n" << RESET;
            std::cin >> input;

            // Controlar EOF (Ctrl+D o Ctrl+Z)
            if (!std::cin) {
                std::cout << RED << "Input stream closed. Exiting...\n" << RESET;
                break;
            }

            // Limpiar el resto del buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Convertir a mayúsculas (C++98 compatible)
            for (size_t i = 0; i < input.length(); ++i)
                input[i] = std::toupper(input[i]);

            if (input == "ADD")
                phoneBook.add();
            else if (input == "SEARCH")
                phoneBook.search();
            else if (input == "EXIT")
                break;
            else
                std::cout << input << RED << " <-- COMMAND NOT ALLOWED\n" << RESET;
        }
    }
    else
    {
        std::cout << RED << "This program does not accept arguments.\n" << RESET;
    }

    return 0;
}
