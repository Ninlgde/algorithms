#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>
#include "list.h"

typedef struct CListElmt_ {
  void *data;
  struct CListElmt_ *next;
}CListElmt;

typedef struct CList_ {
  int size;
  int (*match)(const void key1, const void key2);
  void (*destroy)(void *data);
  CListElmt *head;
}CList;

/*    public interface    */
void clist_init(CList *list, void (*destroy)(void *data));
void clist_destroy(CList *list);
int clist_ins_next(CList *list, CListElmt *element, const void *data);
int clist_rem_next(CList *list, CListElmt *element, void **data);

/* use list.h
#define clist_size(list) ((list)->size) list_size
#define clist_head(list) ((list)->head) list_head
#define clist_data(element) ((element)->data) list_data
#define clist_next(element) ((element)->next) list_next
*/

#endif
