/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:32:33 by sergio            #+#    #+#             */
/*   Updated: 2025/07/09 12:19:49 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"
#include "../include/phonebook.hpp"

// Muestra el mensaje inicial del programa
void initPhoneBook()
{
    std::cout << CYAN << "PHONE BOOK\n" << RESET;
    std::cout << CYAN
            << "COMMAND ALLOWED:\n"
            << "- ADD: save a new contact\n"
            << "- SEARCH: display a specific contact\n"
            << "- EXIT: The program quits and the contacts are lost forever\n\n"
            << RESET;
}

// Solicita al usuario un campo y valida que no esté vacío
// También valida que el número de teléfono tenga 9 dígitos exactos si aplica
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

        // Verificar que no sea todo espacios
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

        // Eliminar espacios al inicio y al final
        std::size_t start = input.find_first_not_of(" \t");
        std::size_t end = input.find_last_not_of(" \t");
        input = input.substr(start, end - start + 1);

        // Validar número de teléfono si aplica
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

// Formatea un campo a exactamente 10 caracteres: truncando o alineando a la derecha
std::string formatField(const std::string &field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";

    std::string formatted(10 - field.length(), ' ');
    formatted += field;
    return formatted;
}
