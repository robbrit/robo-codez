/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#include "observers.h"

const int OBS_100MS  = 0;
const int OBS_500MS  = 1;
const int OBS_1000MS = 2;

int light_on = 0;
const int LIGHT_PORT = 2;

void light(){
  if (light_on){
    digitalWrite(LIGHT_PORT, LOW);
  } else {
    digitalWrite(LIGHT_PORT, HIGH);
  }
  light_on = !light_on;
}

void setup(){
  observers_add(OBS_1000MS, light);
}

// Loop management: don't do anything here, if you want to have an action
// then bind it to an observer

int loop_counter = 0;

void loop(){
  loop_counter++;

  if (loop_counter % 5 == 0){
    observers_trigger(OBS_500MS);
  }

  if (loop_counter == 10){
    loop_counter = 0;
    observers_trigger(OBS_1000MS);
  }

  observers_trigger(OBS_100MS);

  delay(100);
}
