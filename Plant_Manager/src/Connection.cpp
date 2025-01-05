/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Connection.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:15:23 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/05 14:01:29 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Connection.hpp"


Connection::Connection():_user(this->getString("name","\0").c_str()),_pass(this->getString("pass","\0").c_str()),_status(NOT_CONNECTED){}

bool Connection::getStatus(void)
{
    return (this->_status);
}

void Connection::setStatus(bool status)
{
    this->_status = status;
}

void Connection::connect(const char *user,const char *pass)
{
    bool res = this->autoConnect(this->_user, this->_pass);
    while(!res)
    {
        Serial.printf ("Trying to connect..., if it takes too long consider check your connection.\n");
        res = this->autoConnect(this->_user, this->_pass);
    }
    if (res)
    {
        Serial.printf("Connected!");
        this->setStatus(CONNECTED);
    }
}





