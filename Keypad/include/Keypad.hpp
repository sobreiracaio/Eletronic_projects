/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keypad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:58:42 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/09 21:17:48 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Conf.hpp"

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