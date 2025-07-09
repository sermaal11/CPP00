/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:11:00 by sergio            #+#    #+#             */
/*   Updated: 2025/07/09 10:23:22 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define RED "\033[31m"
# define RESET "\033[0m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define GREEN "\033[32m"
# include "../include/contact.hpp"
# include <iostream>
# include <cctype>
# include <limits>

class PhoneBook
{
    private:
        Contact _list[8];
        int     _count;

    public:
        PhoneBook();
        void add();
        // void search( -??- )
};

std::string completeContact(std::string fieldName);

#endif