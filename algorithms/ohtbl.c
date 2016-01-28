//
//  ohtbl.c
//  algorithms
//
//  Created by MalikMa on 15/9/1.
//  Copyright (c) 2015年 ninlgde. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include "ohtbl.h"

static char vacated;

int ohtbl_init(OHTbl *htbl, int positions,
               int (*h1)(const void *key, int len),
               int (*h2)(const void *key, int len),
               int (*match)(const void *key1, const void *key2),
               void (*destroy)(void *data)) {
    int i;
    if ((htbl->table = (void **)malloc(positions * sizeof(void *))) == NULL) {
        return -1;
    }
    htbl->positions = positions;
    for (i = 0; i < htbl->positions; i++) {
        htbl->table[i] = NULL;
    }
    htbl->vacated = &vacated;
    htbl->h1 = h1;
    htbl->h2 = h2;
    htbl->match = match;
    htbl->destroy = destroy;
    htbl->size = 0;
    return 0;
}

void ohtbl_destroy(OHTbl *htbl) {
    int i;
    if (htbl->destroy != NULL) {
        for (i = 0; i < htbl->positions; i++) {
            if (htbl->table[i] != NULL && htbl->table[i] != htbl->vacated) {
                htbl->destroy(htbl->table[i]);
            }
        }
    }
    free(htbl->table);
    memset(htbl, 0, sizeof(OHTbl));
    return;
}

int ohtbl_insert(OHTbl *htbl, const void *data) {
    void *temp;
    int position, i;
    if (htbl->size == htbl->positions) {
        return -1;
    }
    temp = (void *)data;
    if (ohtbl_lookup(htbl, &temp) == 0) {
        return 1;
    }
    for (i = 0; i < htbl->positions; i++) {
        position = (htbl->h1(data, htbl->positions) + (i * htbl->h2(data, htbl->positions))) % htbl->positions;
        if (htbl->table[position] == NULL ||
            htbl->table[position] == htbl->vacated) {
            htbl->table[position] = (void *)data;
            htbl->size++;
            return 0;
        }
    }
    return -1;
}

int ohtbl_remove(OHTbl *htbl, void **data) {
    int position, i;
    for (i = 0; i < htbl->positions; i++) {
        position = (htbl->h1(data, htbl->positions) + (i * htbl->h2(data, htbl->positions))) % htbl->positions;
        if (htbl->table[position] == NULL) {
            return -1;
        } else if (htbl->table[position] == htbl->vacated) {
            continue;
        } else if (htbl->match(htbl->table[position], *data)) {
            *data = htbl->table[position];
            htbl->table[position] = htbl->vacated;
            htbl->size--;
            return 0;
        }
    }
    return -1;
}

int ohtbl_lookup(const OHTbl *htbl, void **data) {
    int position, i;
    for (i = 0; i < htbl->positions; i++) {
        position = (htbl->h1(data, htbl->positions) + (i * htbl->h2(data, htbl->positions))) % htbl->positions;
        if (htbl->table[position] == NULL) {
            return -1;
        } else if (htbl->table[position] == htbl->vacated) {
            continue;
        } else if (htbl->match(htbl->table[position], *data)) {
            *data = htbl->table[position];
            return 0;
        }
    }
    return -1;
}
