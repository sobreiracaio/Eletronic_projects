/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keypad.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:28:55 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/22 01:16:13 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Keypad.hpp"

Keypad::Keypad(std::deque<std::string> (&commandTable)[BUTTON_NBR], std::deque<int> (&typesTable)[BUTTON_NBR]): _commandMatrix(commandTable), _commandTypes(typesTable)
{
    for(int i = 0; i < BUTTON_NBR; i++)
    {
        this->_commandMatrix[i] = commandTable[i];
    }
    for(int i = 0; i < BUTTON_NBR; i++)
    {
        this->_commandTypes[i] = typesTable[i];
    }
    
}

void Keypad::_execByType(std::string value, int type)
{
    const char *str = value.c_str();
    switch (type)
    {
        case KEY:
            //this->write(*str);
            Serial.printf("Letter is: %c", *str);
            break;
        case TEXT:
        Serial.printf("Letter is: %s", str);
            break;
        case MACRO:
            break;
        case RUN:
            break;
    }
}




void Keypad::execute(int button)
{
    if(button == -1)
        return;
    
    for (int i = 0; i < BUTTON_NBR; i++ )
    {
        
        if(i == button)
        {
            this->_execByType(this->_commandMatrix->at(i - 1), this->_commandTypes->at(i - 1));
        }
    }
    
}