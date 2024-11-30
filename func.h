#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include "item.h"
#include "character.h"
#include "location.h"
#include "npc.h"

void inputCharacter(Character *character);
void inputLocation(Location *location);
void inputItem(Item *item);
void inputNPC(NPC *npc);
void saveToFile(const char *filename, Character *characters, int characterCount, Location *locations, int locationCount, Item *items, int itemCount, NPC *npcs, int npcCount);

#endif //FUNC_H_INCLUDED