/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:56:58 by sergio            #+#    #+#             */
/*   Updated: 2025/07/09 10:14:17 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"
#include "../include/phonebook.hpp"

// Formatear campos para el search
std::string formatField(const std::string &field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    
    std::string formatted(10 - field.length(), ' ');
    formatted += field;
    return formatted;
}

