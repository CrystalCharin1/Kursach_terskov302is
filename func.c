#include <stdio.h>
#include "item.h"
#include "character.h"
#include "location.h"
#include "npc.h"
#include "func.h"

#define MAX_HISTORY_LENGTH 1000
#define MAX_DESCRIPTION_LENGTH 500
#define MAX_ITEM_TYPE_LENGTH 50
#define MAX_LOCATION_NAME_LENGTH 50
#define MAX_ITEM_NAME_LENGTH 100
#define MAX_LOCATION_TYPE_LENGTH 50
#define MAX_NPC_NAME_LENGTH 100

#define MAX_CHARACTERS 100
#define MAX_LOCATIONS 100
#ifndef MAX_ITEMS
#define MAX_ITEMS 10
#endif
#define MAX_NAME_LENGTH 100
#ifndef MAX_DESCRIPTION_LENGTH
#define MAX_DESCRIPTION_LENGTH 1000
#endif

Location locations[MAX_LOCATIONS];
int locationCount = 0;

Item items[MAX_ITEMS];
int itemCount = 0;

void inputCharacter(Character *character_p) { //Данная функция отвечает за персонажа(ей)
    printf("Enter character's first name: ");
    scanf("%s", character_p->firstName);
    printf("Enter character's last name: ");
    scanf("%s", character_p->lastName);
    printf("Enter height (in meters): ");
    scanf("%f", &character_p->height);
    printf("Enter weight (in kilograms): ");
    scanf("%f", &character_p->weight);
    printf("Enter character's history: ");
    getchar();
    fgets(character_p->history, MAX_HISTORY_LENGTH, stdin);
}

void inputLocation(Location *location_p) {
    printf("Enter location type: ");
    scanf("%s", location_p->type);
    printf("Enter location name: ");
    scanf("%s", location_p->name_loc);
    printf("Enter location size: ");
    scanf("%f", &location_p->size);
    printf("Enter location description: ");
    getchar();
    fgets(location_p->description, MAX_DESCRIPTION_LENGTH, stdin);
    
    locations[locationCount++] = *location_p;
}

void inputItem(Item *item_p) {
    printf("Enter item type: ");
    scanf("%s", item_p->type);
    printf("Enter item name: ");
    scanf("%s", item_p->name_item);
    printf("Enter item quantity: ");
    scanf("%d", &item_p->quantity);
    
    items[itemCount++] = *item_p;
}

void inputNPC(NPC *npc_p) {
    printf("Enter NPC name: ");
    scanf("%s", npc_p->name_npc);
    
    if (locationCount > 0) {
        printf("Select a location (0 to %d):\n", locationCount - 1);
        for (int i = 0; i < locationCount; i++) {
            printf("%d: %s\n", i, locations[i].name_loc);
        }
        int locIndex;
        scanf("%d", &locIndex);
        npc_p->location = locations[locIndex];
    } else {
        inputLocation(&npc_p->location);
    }

    printf("Enter number of items with the NPC: ");
    scanf("%d", &npc_p->itemCount);
    for (int i = 0; i < npc_p->itemCount; i++) {
        if (itemCount > 0) {
            printf("Select an item (0 to %d):\n", itemCount - 1);
            for (int j = 0; j < itemCount; j++) {
                printf("%d: %s\n", j, items[j].name_item);
            }
            int itemIndex;
            scanf("%d", &itemIndex);
            npc_p->items[i] = items[itemIndex];
        } else {
            inputItem(&npc_p->items[i]);
        }
    }
}

void saveToFile(const char *filename, Character *characters, int characterCount, Location *locations, int locationCount, Item *items, int itemCount, NPC *npcs, int npcCount) {
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < characterCount; i++) {
        fprintf(file, "Character: %s %s, Height: %.2f, Weight: %.1f, History: %s\n",
                characters[i].firstName, characters[i].lastName,
                characters[i].height, characters[i].weight, characters[i].history);
    }

    for (int i = 0; i < locationCount; i++) {
        fprintf(file, "Location: %s, Location name: %s, Size: %.2f, Description: %s\n",
                locations[i].type, locations[i].name_loc, locations[i].size, locations[i].description);
    }

    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "Item: %s, Name: %s, Quantity: %d\n",
                items[i].type, items[i].name_item, items[i].quantity);
    }

    for (int i = 0; i < npcCount; i++) {
        fprintf(file, "NPC: %s, Location: %s, ItemCount: %d\n",
                npcs[i].name_npc, npcs[i].location.name_loc, npcs[i].itemCount);
        for (int j = 0; j < npcs[i].itemCount; j++) {
            fprintf(file, "  Item %d: %s\n", j + 1, npcs[i].items[j].name_item);
        }
    }

    fclose(file);
}