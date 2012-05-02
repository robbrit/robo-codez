/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include "data_structures.h"

/*********** LIST FUNCTIONS **********/

// creates a new list with element obj and the next cell
struct list * list_create(void * obj, struct list * next){
  struct list * l = (struct list *)malloc(sizeof(struct list));

  l->obj = obj;
  l->next = next;
}

// removes obj from l
struct list * list_remove(void * obj, struct list * l){
  if (l == 0){
    return 0;
  }

  // edge case: obj is at the front
  if (l->obj == obj){
    struct list * next = l->next;
    free(l);
    return next;
  }

  // otherwise just loop through looking for it
  struct list * current = l->next;
  struct list * prev = l;

  while (current != 0){
    if (current->obj == obj){
      prev->next = current->next;
      free(current);
      return l;
    }
    prev = current;
    current = current->next;
  }
  return l;
}

// delete a list
void list_delete(struct list * l){
  if (l == 0){
    return;
  }

  list_delete(l->next);
  free(l);
}
