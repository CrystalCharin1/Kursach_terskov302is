#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character.h"
#include "location.h"
#include "item.h"
#include "npc.h"
#include "func.h"

#define MAX_NAME_LENGTH 100
#define MAX_CHARACTERS 10
#define MAX_ITEMS 10
#define MAX_NPCS 10



int main() {
    Character characters[MAX_CHARACTERS];
    Location locations[MAX_CHARACTERS];
    Item items[MAX_ITEMS];
    NPC npcs[MAX_NPCS];
    int characterCount = 0, locationCount = 0, itemCount = 0, npcCount = 0;
    char filename[MAX_NAME_LENGTH];

    printf("Enter filename for saving: ");
    fgets(filename, MAX_NAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;

    char choice;
    do {
        if (characterCount < MAX_CHARACTERS) {
            inputCharacter(&characters[characterCount]);
            characterCount++;
        } else {
            printf("Maximum number of characters reached.\n");
            break;
        }
        printf("Do you want to enter another character? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    do {
        if (locationCount < MAX_CHARACTERS) {
            inputLocation(&locations[locationCount]);
            locationCount++;
        } else {
            printf("Maximum number of locations reached.\n");
            break;
        }
        printf("Do you want to enter another location? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    do {
        if (itemCount < MAX_ITEMS) {
            inputItem(&items[itemCount]);
            itemCount++;
        } else {
            printf("Maximum number of items reached.\n");
            break;
        }
        printf("Do you want to enter another item? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    do {
        if (npcCount < MAX_NPCS) {
            inputNPC(&npcs[npcCount]);
            npcCount++;
        } else {
            printf("Maximum number of NPCs reached.\n");
            break;
        }
        printf("Do you want to enter another NPC? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    saveToFile(filename, characters, characterCount, locations, locationCount, items, itemCount, npcs, npcCount);
    printf("Data saved to file %s.\n", filename);

    return 0;
}