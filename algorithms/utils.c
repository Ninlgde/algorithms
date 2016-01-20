#include "utils.h"

int n_swap(void *x, void *y, int size)
{
  void *tmp;
  if ((tmp = malloc(size)) == NULL) {
    return -1;
  }
  memcpy(tmp, x, size);
  memcpy(x, y, size);
  memcpy(y, tmp, size);
  free(tmp);
  return 0;
}
