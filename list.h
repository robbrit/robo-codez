/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details. */

#ifndef LIST_H
#define LIST_H

#include <stdlib.h> // for malloc

template <class T>
class list {
  class node {
  public:
    T obj;
    node * next;
  };
  node * root;
public:
  class iterator {
    node * current;
  public:
    iterator(node * _c) : current(_c) {}

    T & operator *() { return current->obj; }
    void operator++() { current = current->next; }
    void operator++(int) { current = current->next; }
    bool operator==(const iterator &it) { return current == it.current; }
    bool operator!=(const iterator &it) { return current != it.current; }
  };

  list() : root(0) {}

  ~list(){
    // clean up some memory
    node * current = root;
    while (current != 0){
      node * next = current->next;
      free(current);
      current = next;
    }
    root = 0;
  }

  iterator begin() { 
    return iterator(root);
  }

  iterator end(){
    return iterator(0);
  }

  // iterates over the list
  void foreach(iterator it){
    node * current = root;
    while (current != 0){
      it(current->obj);
      current = current->next;
    }
  }

  // adds a new object to the front of the list
  void push(T obj){
    root = (node *)malloc(sizeof(node));
    root->obj = obj;
    root->next = 0;
  }

  // removes an object from the list
  void remove(T obj){
    if (root == 0){
      return;
    }

    // edge case: obj is at the front
    if (root->obj == obj){
      node * next = root->next;
      free(root);
      root = next;
      return;
    }

    // otherwise just loop through looking for it
    node * current = root->next;
    node * prev = root;

    while (current != 0){
      if (current->obj == obj){
        prev->next = current->next;
        free(current);
        return;
      }
      prev = current;
      current = current->next;
    }
  }
};

#endif // LIST_H
