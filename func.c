#include <stdio.h>
#include "item.h"
#include "character.h"
#include "location.h"
#include "npc.h"
#include "func.h"

#define MAX_HISTORY_LENGTH 1000
#define MAX_DESCRIPTION_LENGTH 500
#define MAX_ITEM_TYPE_LENGTH 50
#define MAX_ITEM_NAME_LENGTH 100
#define MAX_LOCATION_TYPE_LENGTH 50
#define MAX_NPC_NAME_LENGTH 100

void inputCharacter(Character *character) { //Данная функция отвечает за персонажа(ей)
    printf("Enter character's first name: ");
    scanf("%s", character->firstName);
    printf("Enter character's last name (leave empty if none): ");
    scanf("%s", character->lastName);
    printf("Enter height (in meters): ");
    scanf("%f", &character->height);
    printf("Enter weight (in kilograms): ");
    scanf("%f", &character->weight);
    printf("Enter character's history: ");
    getchar();
    fgets(character->history, MAX_HISTORY_LENGTH, stdin);
}

void inputLocation(Location *location) { // Данная функция отвечает за локацию(ии)
    printf("Enter location type: ");
    scanf("%s", location->type);
    printf("Enter location size: ");
    scanf("%f", &location->size);
    printf("Enter location description: ");
    getchar();
    fgets(location->description, MAX_DESCRIPTION_LENGTH, stdin);
}

void inputItem(Item *item) { // Данная функция отвечает за предмет(ы)
    printf("Enter item type: ");
    scanf("%s", item->type);
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);
}

void inputNPC(NPC *npc) { // Данная функция отвечает за npc(персонаж(и), которым(ы) не управляет игрок) 
    printf("Enter NPC name: ");
    scanf("%s", npc->name);
    inputLocation(&npc->location);
    printf("Enter number of items with the NPC: ");
    scanf("%d", &npc->itemCount);
    for (int i = 0; i < npc->itemCount; i++) {
        printf("Enter details for item %d:\n", i + 1);
        inputItem(&npc->items[i]);
    }
}

void saveToFile(const char *filename, Character *characters, int characterCount, Location *locations, int locationCount, Item *items, int itemCount, NPC *npcs, int npcCount) {
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < characterCount; i++) {
        fprintf(file, "Character: %s %s, Height: %.1f, Weight: %.1f, History: %s\n",
                characters[i].firstName, characters[i].lastName,
                characters[i].height, characters[i].weight, characters[i].history);
    }

    for (int i = 0; i < locationCount; i++) {
        fprintf(file, "Location: %s, Size: %d, Description: %s\n",
                locations[i].type, locations[i].size, locations[i].description);
    }

    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "Item: %s, Name: %s, Quantity: %d\n",
                items[i].type, items[i].name, items[i].quantity);
    }

    for (int i = 0; i < npcCount; i++) {
        fprintf(file, "NPC: %s, Location: %s, ItemCount: %d\n",
                npcs[i].name, npcs[i].location, npcs[i].itemCount);
    }

    fclose(file);
}