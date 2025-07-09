/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:56:58 by sergio            #+#    #+#             */
/*   Updated: 2025/07/09 11:34:20 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"
#include "../include/phonebook.hpp"

PhoneBook::PhoneBook() : _count(0)
{
    std::cout << RED << "[DEBUG] Constructor de PhoneBook ejecutado\n" << RESET;
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

void PhoneBook::search()
{
    if (_count == 0)
        std::cout << RED << "There are no saved contacts.\n" << RESET;
    else
        std::cout << CYAN
                << std::setw(10) << "|    Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << "|" << "\n"
                << RESET;
    // 1 Funcion que muestre toda la lista de contactos guardados
    // 2 Preguntar si se quiere acceder a un contacto en especifico para ver los detalles introduciendo un numero del 0 al 7
    // 3 arbol de decision si se entra o no al flujo anterior
    std::cout << RED << "[DEBUG] " << "Metodo SEARCH ejecutadpo con exito\n" << RESET;
}

