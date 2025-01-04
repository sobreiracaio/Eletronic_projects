/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WiFi.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:08:31 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/04 16:58:12 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WiFiManager.h"
#include <string>

#define CONNECTED 1
#define NOT_CONNECTED 0

class WifiConnection {
    private:
        const std::string _user;
        const std::string _pass;
        bool _status;
        void _reconnect(void);
    public:
        WifiConnection(std::string const &user, std::string const &pass, bool status);
        bool getStatus(void);
        void setStatus(bool status);
        void setUser(std::string const user);
        void setPass(std::string const pass);
        bool connect(void);
};