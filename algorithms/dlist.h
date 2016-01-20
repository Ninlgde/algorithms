#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>
#include "list.h"

typedef struct DListElmt_
{
  void *data;
  struct DListElmt_ *prev;
  struct DListElmt_ *next;
}DListElmt;

typedef struct DList_
{
  int size;
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);
  DListElmt *head;
  DListElmt *tail;
}DList;

/*      public interface      */
void dlist_init(DList *list, void (*destroy)(void *data));
void dlist_destroy(DList *list);
int dlist_ins_next(DList *list, DListElmt element, const void *data);
int dlist_ins_prev(DList *list, DListElmt element, const void *data);
int dlist_remove(DList *list, DListElmt element, void **data);

/* use list.h
#define dlist_size(list) ((list)->size) list_size
#define dlist_head(list) ((list)->head) list_head
#define dlist_tail(list) ((list)->tail) list_tail
#define dlist_data(element) ((element)->data) list_data
#define dlist_next(element) ((element)->next) list_next
*/
#define dlist_is_head(element) ((element)->prev == NULL ? 1 : 0)
#define dlist_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define dlist_prev(element) ((element)->prev)

#endif
