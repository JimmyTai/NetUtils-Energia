//
//  JNetUtils.h
//  Arduino-JNet
//
//  Created by GRC on 2017/1/5.
//  Copyright © 2017年 JimmyTai. All rights reserved.
//

#ifndef JNetUtils_h
#define JNetUtils_h

#include <WString.h>

class UrlEncoder{
    
public:
    
    String encode(const String& str);
    
private:
    
    char toHex(unsigned char x);
};

extern UrlEncoder UrlEncoder;

class UrlDecoder{
    
public:
    
    String decode(const String& str);
    
private:
    
    unsigned char fromHex(unsigned char x);
};

extern UrlDecoder UrlDecoder;

#endif /* JNetUtils_h */
