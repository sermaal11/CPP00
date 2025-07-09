/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:33:06 by sergio            #+#    #+#             */
/*   Updated: 2025/07/09 10:14:30 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"
#include "../include/phonebook.hpp"

// ! [DEBUG]
void Contact::displayFull() const
{
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone Number: " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

void PhoneBook::add()
{
    Contact contact;
    
    contact.setFirstName(completeContact("First Name: "));
    contact.setLastName(completeContact("Last Name: "));
    contact.setNickname(completeContact("Nickname: "));
    contact.setPhoneNumber(completeContact("Phone Number: "));
    contact.setDarkestSecret(completeContact("Darkest Secret: "));

    // ! [DEBUG]
    std::cout << RED << "[DEBUG] " << "Contacto creado con éxito. Datos almacenados:\n" << RESET;
    contact.displayFull();
    // ! [DEBUG]
}

void initPhoneBook()
{
    std::cout << CYAN << "PHONE BOOK\n" << RESET;
    std::cout << CYAN << "COMMAND ALLOWED: - ADD: save a new contact. - SEARCH: display a specific contact - EXIT: The program quits and the contacts are lost forever\n\n" << RESET;
}

int main (int argc, char **argv)
{
    (void) argv;
    std::string input;
    PhoneBook contactList;
    
    if (argc == 1)
    {
        initPhoneBook();
        while(1)
        {
            std::cout << GREEN << "WAITING COMMAND:\n" << RESET;
            std::cin >> input;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (input == "ADD")
                contactList.add();
            else if (input == "SEARCH")
                std::cout << RED << "Comando no implementado\n" << RESET;
            else if (input == "EXIT")
                break;
            else
                std::cout << input << RED << " <-- COMMAND NOT ALLOWED\n" << RESET;
        }
    }
    return (0);
}

