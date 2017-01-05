//
//  UrlDecoder.cpp
//  Arduino-JNet
//
//  Created by GRC on 2017/1/5.
//  Copyright © 2017年 JimmyTai. All rights reserved.
//

#include "JNetUtils.h"

class UrlDecoder UrlDecoder;

unsigned char UrlDecoder::fromHex(unsigned char x)
{
    unsigned char y;
    if (x >= 'A' && x <= 'Z') y = x - 'A' + 10;
    else if (x >= 'a' && x <= 'z') y = x - 'a' + 10;
    else if (x >= '0' && x <= '9') y = x - '0';
    return y;
}

String UrlDecoder::decode(const String &str){
    String strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++) {
        if (str[i] == '+')
            strTemp += ' ';
        else if(str[i] == '%'){
            if(i + 2 >= length)
                continue;
            unsigned char high = fromHex((unsigned char) str[++i]);
            unsigned char low = fromHex((unsigned char) str[++i]);
            strTemp += (char)(high * 16 + low);
        }
        else strTemp += str[i];
    }
    return strTemp;
}
