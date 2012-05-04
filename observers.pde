/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include "observers.h"

const int MAX_OBSERVERS = 20;

typedef list<observer> observer_list;
typedef list<observer>::iterator observer_iter;

list<observer> observers[MAX_OBSERVERS];

void observers_add(unsigned int what, observer obs){
  if (what < MAX_OBSERVERS){
    observers[what].push(obs);
  }
}

void observers_remove(unsigned int what, observer obs){
  if (what < MAX_OBSERVERS){
    observers[what].remove(obs);
  }
}

void observers_trigger(unsigned int what){
  if (what < MAX_OBSERVERS){
    for (observer_iter it = observers[what].begin();
         it != observers[what].end();
         it++){
      (*it)();
    }
  }
}
