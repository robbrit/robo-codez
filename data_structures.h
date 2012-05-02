/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

struct list {
  void * obj;
  struct list * next;
};

// creates a new list
struct list * list_create(void * obj, struct list * next);

// removes an element from the list
struct list * list_remove(void * obj, struct list * l);

// deletes a list
void list_delete(struct list * l);

// pushes a new object on to a list
#define list_push list_create
