/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include "observers.h"

const int MAX_OBSERVERS = 20;
struct list ** observers;

void observers_init(){
  int i;

  observers = (struct list**)malloc(sizeof(struct list*) * MAX_OBSERVERS);

  for (i = 0; i < MAX_OBSERVERS; i++){
    observers[i] = 0;
  }
}

void observers_add(unsigned int what, observer obs){
  if (what < MAX_OBSERVERS){
    if (observers[what] == 0){
      observers[what] = list_create(obs, 0);
    } else {
      observers[what] = list_push(obs, observers[what]);
    }
  }
}

void observers_remove(unsigned int what, observer obs){
  if (what < MAX_OBSERVERS && observers[what] != 0){
    observers[what] = list_remove(obs, observers[what]);
  }
}

void observers_trigger(unsigned int what, void * param){
  if (what < MAX_OBSERVERS && observers[what] != 0){
    struct list * current = observers[what];

    while (current != 0){
      observer obs = (observer)current->obj;
      obs(param);
      current = current->next;
    }
  }
}
