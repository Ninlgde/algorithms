//
//  cover.h
//  algorithms
//
//  Created by MalikMa on 15/8/19.
//  Copyright (c) 2015年 ninlgde. All rights reserved.
//

#ifndef __algorithms__cover__
#define __algorithms__cover__

#include "set.h"

typedef struct KSet_ {
    void *key;
    Set set;
} KSet;

int cover(Set *member, Set *subsets, Set *covering);

#endif /* defined(__algorithms__cover__) */
