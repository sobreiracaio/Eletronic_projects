/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:10:33 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/02 01:23:04 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser(String rawData):_rawData(rawData){}


static std::string trim(std::string const &data)
{
    int begin = data.find_first_not_of(" ");
    int end = data.find_last_not_of(" ");
    
    if (begin == std::string::npos)
        return "";
    std::string subStr = data.substr(begin, end - begin + 1);
    return (subStr);
}


std::deque<std::string> Parser::readFromFile(int dataType)
{
    std::stringstream raw (this->_rawData.c_str());
    std::string line;
    std::deque<std::string> deque;
         
    while(std::getline(raw, line))
    {
        std::string discardBT;
        std::string tmpCmdType;
        std::string tmpCmdValue;
        
        std::getline(raw,discardBT, '|');
        std::getline(raw,tmpCmdType, '>');
        raw >> tmpCmdValue;
        if(dataType == TYPE )
        {
            std::string trimmed = trim(tmpCmdType);
            deque.push_back(trimmed);
        }
        else if (dataType == VALUE)
        {
            std::string trimmed = trim(tmpCmdValue);
            deque.push_back(trimmed);
        }
         
    }
    return (deque);
}
