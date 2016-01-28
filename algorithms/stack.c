//
//  stack.c
//  algorithms
//
//  Created by MalikMa on 15/8/19.
//  Copyright (c) 2015年 ninlgde. All rights reserved.
//

#include <stdlib.h>
#include "list.h"
#include "stack.h"

int stack_push(Stack *stack, const void *data) {
    return list_ins_next(stack, NULL, data);
}

int stack_pop(Stack *stack, void **data) {
    return list_rem_next(stack, NULL, data);
}