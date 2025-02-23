/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:18:06 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/23 01:48:01 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Keypad.hpp"


class Parser{
    private:
        String _rawData;
    public:
        Parser(String rawData);
        std::deque<int> parseType();
        //std::deque<std::string> parseValue();
};