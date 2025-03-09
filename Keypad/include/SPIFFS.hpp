/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SPIFFS.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:15:43 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/09 21:19:14 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Conf.hpp"

String getSPIFFS()
{
  File file;
  String contents;

  
  if (!SPIFFS.begin(true)) 
  {
    Serial.println("Erro ao montar o SPIFFS!");
    return ("ERROR");
  }
  Serial.println("SPIFFS montado com sucesso!");

  if (!SPIFFS.exists("/conf.txt")) 
  {
    Serial.println("Arquivo /conf.txt não encontrado no SPIFFS!");
    return ("ERROR");
  }
  Serial.println("Arquivo existe!");

  file = SPIFFS.open("/conf.txt");
  if(!file)
  {
    Serial.println("Erro ao abrir o arquivo!");
    return ("ERROR");
  }
  Serial.println("Arquivo Aberto");
  contents = file.readString();
  file.close();

  return (contents);
}