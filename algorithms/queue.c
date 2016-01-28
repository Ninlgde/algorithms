//
//  queue.c
//  algorithms
//
//  Created by MalikMa on 15/8/19.
//  Copyright (c) 2015年 ninlgde. All rights reserved.
//

#include <stdlib.h>
#include "list.h"
#include "queue.h"

int queue_enqueue(Queue *queue, const void *data) {
    return list_ins_next(queue, list_tail(queue), data);
}

int queue_dequeue(Queue *queue, void **data) {
    return list_rem_next(queue, NULL, data);
}
