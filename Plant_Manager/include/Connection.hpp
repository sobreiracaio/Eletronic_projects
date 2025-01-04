/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Connection.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:08:31 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/04 21:36:30 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WiFiManager.h"
#include "Preferences.h"


#define CONNECTED 1
#define NOT_CONNECTED 0

WiFiManager wifi;
Preferences nonVolatileData;

class Connection{
    private:
        const char *_user;
        const char *_pass;
        bool _status;
        bool _isFirstConnection;
        
    public:
        Connection();
        void wifiPortal(void);
        bool getStatus(void);
        void setStatus(bool status);
        bool connect(char *user,char *pass);
};

    