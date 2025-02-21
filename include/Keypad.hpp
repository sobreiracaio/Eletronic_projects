/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keypad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:58:42 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/21 22:47:10 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <BleKeyboard.h>
#include <list>
#include <string>

#define BUTTON_NBR 15

#define KEY 0
#define TEXT 1
#define MACRO 2
#define RUN 3

class Keypad: public BleKeyboard{
    private:
        std::list<std::string> _commandMatrix[BUTTON_NBR];
        std::list<int> _commandTypes[BUTTON_NBR];
        void _execByType(std::string value, int type);
    
    public:
        Keypad(std::list<std::string> commandTable[BUTTON_NBR], std::list<int> commandTypes[BUTTON_NBR]);
        
        void setCommand(std::string command);
        void execute(int button, int cmdType);

        void sendKey();
        
    
};