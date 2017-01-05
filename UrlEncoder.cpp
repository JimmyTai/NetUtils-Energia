//
//  UrlEncoder.cpp
//  Arduino-JNet
//
//  Created by GRC on 2017/1/5.
//  Copyright © 2017年 JimmyTai. All rights reserved.
//

#include "JNetUtils.h"

class UrlEncoder UrlEncoder;

char UrlEncoder::toHex(unsigned char x){
    return x > 9 ? x + 55 : x + 48;
}

String UrlEncoder::encode(const String& str){
    String strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++) {
        if (isalnum((unsigned char) str[i]) ||
            (str[i] == '-') ||
            (str[i] == '_') ||
            (str[i] == '.') ||
            (str[i] == '~'))
            strTemp += str[i];
        else if (str[i] == ' ')
            strTemp += '+';
        else{
            strTemp += '%';
            strTemp += toHex((unsigned char) (str[i] >> 4));
            strTemp += toHex((unsigned char) (str[i] % 16));
        }
    }
    return strTemp;
}
