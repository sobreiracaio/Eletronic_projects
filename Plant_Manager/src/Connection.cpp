/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Connection.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:15:23 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/04 20:46:20 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Connection.hpp"


Connection::Connection():_user(nonVolatileData.getString("name","\0").c_str()),_pass(nonVolatileData.getString("pass","\0").c_str()),_status(NOT_CONNECTED){}

bool Connection::getStatus(void)
{
    return (this->_status);
}

void Connection::setStatus(bool status)
{
    this->_status = status;
}

bool Connection::connect(char *user,char *pass)
{
    bool res = wifi.autoConnect(this->_user, this->_pass);
    while(!res)
    {
        Serial.printf ("Trying to connect..., if it takes too long consider check your connection.\n");
        res = wifi.autoConnect(this->_user, this->_pass);
    }
    if (res)
    {
        Serial.printf("Connected!");
        this->setStatus(CONNECTED);
    }
    
}

void Connection::wifiPortal(void)
{
    WiFi.mode(WIFI_AP);
    
    

}




