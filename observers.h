/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include "data_structures.h"

typedef void(*observer)(void *);

void observers_init();
void observers_add(unsigned int what, observer obs);
void observers_remove(unsigned int what, observer obs);
void observers_trigger(unsigned int what, void * param);
