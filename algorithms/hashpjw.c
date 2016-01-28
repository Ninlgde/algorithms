//
//  hashpjw.c
//  algorithms
//
//  Created by MalikMa on 15/8/22.
//  Copyright (c) 2015年 ninlgde. All rights reserved.
//

#include "hashpjw.h"

unsigned int hashpjw(const void *key, int len) {
    const char *ptr;
    unsigned int val;
    
    val = 0;
    ptr = key;
    while (*ptr != '\0') {
        unsigned int tmp;
        val = (val << 4) + (*ptr);
        if ((tmp = (val & 0xf0000000))) {
            val = val ^ (tmp >> 24);
            val = val ^ tmp;
        }
        ptr++;
    }
    return val % len;
}