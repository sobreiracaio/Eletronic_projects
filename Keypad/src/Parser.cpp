/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:54:05 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/23 17:33:46 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"



Parser::Parser(String rawData)
{
    this->_rawData = rawData;
}

int populate(std::string type)
{
    std::deque <std::string> types = {"KEY", "TEXT", "MACRO", "RUN"};
    std::string temp = type;
    std::deque<int> ret;
    for(int i = 0; i < types.size(); i++)
    {
        if(temp.find(types[i]) != std::string::npos)
            return (i);
            
    }
    return (-1);
}

std::deque<int> Parser::parseType()
{
    
    std::deque<std::string> rawLines;
    std::deque<int> commandType;
    std::string temp = std::string(this->_rawData.c_str());
   
    
    for (int i = 0; i < temp.size(); i)
    {
        int indexBegin = temp.find_first_of("|",i) + 1;
        int indexEnd = temp.find_first_of("|", indexBegin +1);
        if (indexBegin == std::string::npos )
            return (commandType);
        
        std::string subStr = temp.substr(indexBegin, indexEnd - indexBegin - 1);
            
        if(populate(subStr) >= 0)    
            commandType.push_back(populate(subStr));
                
         
  
            i = indexEnd;
    }
       
    
    return(commandType);
}