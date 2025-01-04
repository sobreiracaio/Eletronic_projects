/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Firebase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:53:26 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/04 16:41:17 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FirebaseClient.h"
#include <string>

class Firebase{
    private:
        const std::string _id;
        const std::string _webAPIKey;
        const std::string _email;

    public:
        Firebase(std::string const id, std::string const webAPIKey, std::string const email);
        void setId (std::string const id);
        void setWebAPIKey (std::string const webAPIKey);
        void setEmail (std::string const email);
};