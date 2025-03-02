/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keypad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:58:42 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/02 22:01:59 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <Arduino.h>
#include <BleKeyboard.h>
#include <deque>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>


#define BUTTON_NBR 15

#define KEY 0
#define TEXT 1
#define MACRO 2
#define RUN 3
#define ERROR -1

#define TYPE 0
#define VALUE 1


class Keypad{
    private:
        std::deque<std::string> _commandMatrix;
        std::deque<std::string> _commandTypes;
        void _execByType(std::string const &value, std::string const &type);
        BleKeyboard *_bt;
    
    public:
        Keypad(BleKeyboard *bt);
        void setCmdMatrix(std::deque<std::string> (commandMatrix), std::deque<std::string> (commandTypes));
        void execute(int button);
   
};