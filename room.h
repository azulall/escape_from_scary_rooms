#ifndef ROOM_H
#define ROOM_H

#define MAX_CONNECTIONS 4
#define MAX_ITEMS 3
#include "creature.h"

typedef struct Room{
    char *description;
    struct Room *connections[MAX_CONNECTIONS];
    char *items[MAX_ITEMS];
    int item_count;
    Creature *creature;
}Room;
void load_room_description(const char *filename, char *description);
Room* create_room(char *description);
void add_item_room(Room *room, char *item);
void display_room(Room *room);
void free_room(Room *room);
void add_creature_room(Room *room, Creature *creature);



#endif