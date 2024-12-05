#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include "item.h"
#include "character.h"
#include "location.h"
#include "npc.h"

void inputCharacter(Character *character_p);
void inputLocation(Location *location_p);
void inputItem(Item *item_p);
void inputNPC(NPC *npc_p);
void saveToFile(const char *filename, Character *characters, int characterCount, Location *locations, int locationCount, Item *items, int itemCount, NPC *npcs, int npcCount);

#endif //FUNC_H_INCLUDED