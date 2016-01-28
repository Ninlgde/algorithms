#ifndef FRAMES_H
#define FRAMES_H

#include "list.h"

int alloc_frames(List *frames);
int free_frames(List *frames, int frame_number);

#endif
