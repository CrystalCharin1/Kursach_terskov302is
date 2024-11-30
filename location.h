#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED

#define MAX_LOCATION_TYPE_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 500

typedef struct {
    char type[MAX_LOCATION_TYPE_LENGTH];
    float size;
    char description[MAX_DESCRIPTION_LENGTH];
} Location;

#endif // LOCATION_H_INCLUDED