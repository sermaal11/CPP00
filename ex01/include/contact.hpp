/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:08:34 by sergio            #+#    #+#             */
/*   Updated: 2025/07/09 12:18:08 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "../include/utils.hpp"
class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    // Setters
    void setFirstName(const std::string& str);
    void setLastName(const std::string& str);
    void setNickname(const std::string& str);
    void setPhoneNumber(const std::string& str);
    void setDarkestSecret(const std::string& str);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    // Mostrar contacto completo
    void displayFull() const;
};

#endif
