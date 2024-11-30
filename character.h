#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#define MAX_NAME_LENGTH 100
#define MAX_HISTORY_LENGTH 1000

typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    float height;
    float weight;
    char history[MAX_HISTORY_LENGTH];
} Character;

#endif //CHARACTER_H_INCLUDED