//
//  stack.h
//  algorithms
//
//  Created by MalikMa on 15/8/19.
//  Copyright (c) 2015年 ninlgde. All rights reserved.
//

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "list.h"

typedef List Stack;

#define stack_init list_init
#define stack_destroy list_destroy
int stack_push(Stack *stack, const void *data);
int stack_pop(Stack *stack, void **data);

#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)

#define stack_size list_size

#endif
