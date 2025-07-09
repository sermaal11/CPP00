/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:33:06 by sergio            #+#    #+#             */
/*   Updated: 2025/07/09 11:01:52 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"
#include "../include/phonebook.hpp"

// ! [DEBUG]
// Método que imprime todos los campos del contacto (para comprobar que se guardó bien)
void Contact::displayFull() const
{
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone Number: " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

// Método que crea un nuevo contacto temporalmente (pero aún no se guarda en _list[])
void PhoneBook::add()
{
    Contact newContact; // Aquí se llama al constructor de Contact (por defecto)
    // Se piden al usuario los distintos campos del contacto
    newContact.setFirstName(completeContact("First Name: "));
    newContact.setLastName(completeContact("Last Name: "));
    newContact.setNickname(completeContact("Nickname: "));
    newContact.setPhoneNumber(completeContact("Phone Number: "));
    newContact.setDarkestSecret(completeContact("Darkest Secret: "));

    int index = _count % 8;
    _list[index] = newContact;
    _count++;

    // ! [DEBUG] Se imprime el contacto creado para ver que está bien
    std::cout << RED << "[DEBUG] Contacto guardado en posición " << index << "\n" << RESET;
    std::cout << RED << "[DEBUG] " << "Contacto creado con éxito. Datos almacenados:\n" << RESET;
    newContact.displayFull();
    // ! [DEBUG]
}

// Muestra el mensaje inicial cuando se lanza el programa sin argumentos
void initPhoneBook()
{
    std::cout << CYAN << "PHONE BOOK\n" << RESET;
    std::cout << CYAN
            << "COMMAND ALLOWED: "
            << "- ADD: save a new contact. "
            << "- SEARCH: display a specific contact "
            << "- EXIT: The program quits and the contacts are lost forever\n\n"
            << RESET;
}

// Punto de entrada del programa
int main (int argc, char **argv)
{
    (void) argv; // Se ignora argv ya que no se usa
    std::string input; // Variable para guardar el comando del usuario
    // Se crea un objeto de tipo PhoneBook
    // Aquí se llama automáticamente al constructor de PhoneBook
    PhoneBook phoneBook;
    // Si el programa se ejecuta sin argumentos adicionales (argc == 1)
    if (argc == 1)
    {
        // Muestra las instrucciones iniciales
        initPhoneBook();
        // Bucle infinito que espera comandos del usuario
        while(1)
        {
            std::cout << GREEN << "WAITING COMMAND:\n" << RESET;
            // Lee el comando que introduce el usuario (una palabra)
            std::cin >> input;
            // Ignora el resto de la línea para evitar conflictos con getline()
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Comando ADD → llama al método phoneBook.add()
            if (input == "ADD")
                phoneBook.add();
            // Comando SEARCH → aún no implementado
            else if (input == "SEARCH")
                std::cout << RED << "Comando no implementado\n" << RESET;
            // Comando EXIT → sale del bucle y finaliza el programa
            else if (input == "EXIT")
                break;
            // Cualquier otro comando → mensaje de comando no válido
            else
                std::cout << input << RED << " <-- COMMAND NOT ALLOWED\n" << RESET;
        }
    }
    return (0); // Fin del programa
}