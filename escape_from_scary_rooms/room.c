#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "room.h"
#include "player.h"
#include "creature.h"
#define MAX_DESC_LENGTH 256

void load_room_description(const char *filename, char *description) {
    FILE *file = fopen(filename, "r"); 
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename); // Dosya açılamazsa hata
        exit(1);
    }

    fgets(description, MAX_DESC_LENGTH, file);

    description[strcspn(description, "\n")] = 0;

    fclose(file);
}

Room* create_room(char *description){
    Room *room = malloc(sizeof(Room));
    if (!room)
    {
        printf("Error! Memory allocation failed.");    
        return NULL;
    }
    room->description = strdup(description);
    room->item_count = 0;
    for (int i = 0; i < MAX_CONNECTIONS; i++)
    {
        room->connections[i] = NULL;
    }
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        room->items[i] = NULL;
    }
    
    return room;
}

void add_item_room(Room *room, char *item){
    if (room->item_count == MAX_ITEMS)
    {
        printf("The item capacity in the room has been reached! No more can be added.\n");
    }
    room->items[room->item_count] = strdup(item);
    room->item_count++;
}

void display_room(Room *room){
    printf("Description of room: %s\n",room->description);
    printf("Items:\n");
    for (int i = 0; i < room->item_count; i++)
    {
        printf("%d. %s\n", i+1, room->items[i]);
    }
    if (room->item_count)
    {
        printf("Room is empty.\n");
    }
    
}

void free_room(Room *room){
    free(room->description);
    for (int i = 0; i < room->item_count; i++)
    {
        free(room->items[i]);
    }
    free(room);
}
void add_creature_room(Room *room, Creature *creature) {
    room->creature = creature;
}

void look_creature(Player *player) {
    printf("You are in: %s\n", player->current_room->description);
    if (player->current_room->creature) {
        printf("A wild %s is here!\n", player->current_room->creature->name);
    }
}
