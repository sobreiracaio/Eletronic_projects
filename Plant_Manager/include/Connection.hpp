/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Connection.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:08:31 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/05 14:30:02 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <WiFiManager.h>
#include <Preferences.h>


#define CONNECTED 1
#define NOT_CONNECTED 0



class Connection: public WiFiManager, public Preferences{
    private:
        const char *_user;
        const char *_pass;
        bool _status;
        bool _isFirstConnection;
        
    public:
        Connection(void);
        bool getStatus(void);
        void setStatus(bool status);
        void connect(const char *user,const char *pass);
};

    