#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "item.h"
#include "location.h"

#define MAX_ITEMS 10
#define MAX_NPC_NAME_LENGTH 100

typedef struct {
    char name[MAX_NPC_NAME_LENGTH];
    Location location;
    Item items[MAX_ITEMS];
    int itemCount;
} NPC;

#endif //NPC_H_INCLUDED