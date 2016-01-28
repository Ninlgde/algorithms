//
//  chtbl.h
//  algorithms
//
//  Created by MalikMa on 15/8/22.
//  Copyright (c) 2015年 ninlgde. All rights reserved.
//

#ifndef __algorithms__chtbl__
#define __algorithms__chtbl__

#include <stdlib.h>
#include "list.h"

typedef struct CHTbl_ {
    int buckets;
    int (*h)(const void *key, int len);
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    int size;
    List *table;
}CHTbl;

int chtbl_init(CHTbl *htbl, int buckets,
               int (*h)(const void *key, int len),
               int (*match)(const void *key1, const void *key2),
               void (*destroy)(void *data));
void chtbl_destroy(CHTbl *htbl);
int chtbl_insert(CHTbl *htbl, const void *data);
int chtbl_remove(CHTbl *htbl, void **data);
int chtbl_lookup(const CHTbl *htbl, void **data);

#define chtbl_size(htbl) ((htbl)->size)

#endif /* defined(__algorithms__chtbl__) */
