/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keypad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:58:42 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/22 14:51:33 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <Arduino.h>
#include <BleKeyboard.h>
#include <deque>
#include <string>


#define BUTTON_NBR 15

#define KEY 0
#define TEXT 1
#define MACRO 2
#define RUN 3

class Keypad: public BleKeyboard{
    private:
        std::deque<std::string> (&_commandMatrix)[BUTTON_NBR];
        std::deque<int> (&_commandTypes)[BUTTON_NBR];
        void _execByType(std::string value, int type);
    
    public:
        Keypad(std::deque<std::string> (&commandTable)[BUTTON_NBR], std::deque<int> (&typesTable)[BUTTON_NBR]);
        
        
        void execute(int button);

        
        
    
};