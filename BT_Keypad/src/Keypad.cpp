/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keypad.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:28:55 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/21 22:56:56 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Keypad.hpp"

Keypad::Keypad(std::list<std::string> commandTable[BUTTON_NBR], std::list<int> commandTypes[BUTTON_NBR])
{
    for(int i = 0; i <= BUTTON_NBR; i++)
    {
        this->_commandMatrix[i] = commandTable[i];
    }
    for(int i = 0; i <= BUTTON_NBR; i++)
    {
        this->_commandTypes[i] = commandTypes[i];
    }
    this->begin();
}

void Keypad::_execByType(std::string value, int type)
{
    const char *str = value.c_str();
    switch (type)
    {
        case KEY:
            this->write(*str);
            break;
        case TEXT:
            this->print(str);
            break;
        case MACRO:
            break;
        case RUN:
            break;
    }
}


void Keypad::execute(int button, int cmdType)
{
    if(button == -1)
        return;
    
    for (int i = 0; i <= BUTTON_NBR; i++ )
    {
        if(i == button)
        {
            this->_execByType(this->_commandMatrix[i], this->_commandTypes[i]);
        }
    }
    
}