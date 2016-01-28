//
//  lex.h
//  algorithms
//
//  Created by MalikMa on 15/8/22.
//  Copyright (c) 2015年 ninlgde. All rights reserved.
//

#ifndef __algorithms__lex__
#define __algorithms__lex__

#include "chtbl.h"

typedef enum Token_ {
    lexit,
    error,
    digit,
    other
}Token;

Token lex(const char *istream, CHTbl *symtbl);

#endif /* defined(__algorithms__lex__) */
