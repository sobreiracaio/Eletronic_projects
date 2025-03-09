/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conf.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:16:55 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/09 21:25:09 by crocha-s         ###   ########.fr       */
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
#include <SPIFFS.h>
#include <FS.h>

#include "soc/soc.h"         // to disable brownout
#include "soc/rtc_cntl_reg.h" // to disable brownout

#define BUTTON_NBR 15

#define KEY 0
#define TEXT 1
#define MACRO 2
#define RUN 3
#define ERROR -1

#define TYPE 0
#define VALUE 1


#define COL0 4
#define COL1 16
#define COL2 17
#define COL3 18
#define COL4 19
#define ROW0 21
#define ROW1 22
#define ROW2 23

#define STATUS_LED 14