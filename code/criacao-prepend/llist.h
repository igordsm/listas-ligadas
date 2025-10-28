#ifndef LLIST_H
#define LLIST_H

#include <stdlib.h>

struct LList {
  int val;

  struct LList *next;  
};

typedef struct LList LList;

#endif
