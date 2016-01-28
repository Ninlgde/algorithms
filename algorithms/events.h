//
//  events.h
//  algorithms
//
//  Created by MalikMa on 15/8/19.
//  Copyright (c) 2015年 ninlgde. All rights reserved.
//

#ifndef __algorithms__events__
#define __algorithms__events__

#include <stdio.h>
#include "queue.h"
#include "event.h"

int receive_event(Queue *events, const Event *event);
int process_event(Queue *events, int (*dispatch)(Event *event));

#endif /* defined(__algorithms__events__) */
