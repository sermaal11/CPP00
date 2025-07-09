/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:08:34 by sergio            #+#    #+#             */
/*   Updated: 2025/07/09 11:27:45 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# define RED "\033[31m"
# define RESET "\033[0m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define GREEN "\033[32m"
# include <iostream>
# include <cctype>
# include <limits>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:
        void setFirstName(const std::string str);
        void setLastName(const std::string str);
        void setNickname(const std::string str);
        void setPhoneNumber(const std::string str);
        void setDarkestSecret(const std::string str);
        std::string getFirstName() const;
        std::string getLasttName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;

        // ! Testeo y DEBUG
        void displayFull() const; // <- Ver contenido del objeto contact
        // ! Testeo y DEBUG 

};

#endif