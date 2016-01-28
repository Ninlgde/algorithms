//
//  ohtbl.h
//  algorithms
//
//  Created by MalikMa on 15/9/1.
//  Copyright (c) 2015年 ninlgde. All rights reserved.
//

#ifndef __algorithms__ohtbl__
#define __algorithms__ohtbl__

#include <stdio.h>
#include <stdlib.h>

typedef struct OHTbl_ {
    int     positions;
    void    *vacated;
    int     (*h1)(const void *key, int len);
    int     (*h2)(const void *key, int len);
    int     (*match)(const void *key1, const void *key2);
    void    (*destroy)(void *data);
    int     size;
    void    **table;
}OHTbl;

int ohtbl_init(OHTbl *htbl, int positions,
               int (*h1)(const void *key, int len),
               int (*h2)(const void *key, int len),
               int (*match)(const void *key1, const void *key2),
               void (*destroy)(void *data));
void ohtbl_destroy(OHTbl *htbl);
int ohtbl_insert(OHTbl *htbl, const void *data);
int ohtbl_remove(OHTbl *htbl, void **data);
int ohtbl_lookup(const OHTbl *htbl, void **data);

#define ohtbl_size(htbl) ((htbl)->size)

#endif /* defined(__algorithms__ohtbl__) */
