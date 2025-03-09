/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:18:06 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/09 21:18:48 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Conf.hpp"


class Parser{
    private:
        String _rawData;
        
    public:
        Parser(String _rawData);
        
        
        std::deque<std::string> readFromFile(int dataType);
};