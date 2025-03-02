/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keypad.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:28:55 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/02 01:22:31 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Keypad.hpp"

Keypad::Keypad(){}

static int returnType(std::string const &typeStr)
{
    std::deque<std::string> tmp = {"KEY", "TEXT", "MACRO", "RUN"};
    int i = 0;
    
    while( i < 4)
    {
        if(typeStr == tmp[i])
            return (i);
        i++;
    }
    return(i);
}

void Keypad::_execByType(std::string const &value, std::string const &types)
{
    int type = returnType(types);
    const char *str = value.c_str();
    
    switch (type)
    {
        case KEY:
            Serial.printf("Letter is: %s", str);
            break;
        case TEXT:
            Serial.printf("Text is: %s", str);
            break;
        case MACRO:
            Serial.printf("Macro is: %s", str);
            break;
        case RUN:
            Serial.printf("Run is: %s", str);
            break;
        case ERROR:
            Serial.printf("ERROR");
            break;
    }
}




void Keypad::execute(int button)
{
    if(button == -1)
        return;
    else
        this->_execByType(this->_commandMatrix[button - 1], this->_commandTypes[button - 1]);
}

void Keypad::setCmdMatrix(std::deque<std::string> commandMatrix, std::deque<std::string> commandTypes)
{
    this->_commandMatrix.clear();
    this->_commandTypes.clear();
    
    for(int i = 0; i < BUTTON_NBR; i++)
    {
        this->_commandMatrix.push_back(commandMatrix[i]);
        this->_commandTypes.push_back(commandTypes[i]);
    }
}