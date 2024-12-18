#ifndef PLAYER_H
#define PLAYER_H

#include "room.h"

#define INVENTORY_SIZE 5

typedef struct Player
{
    char name[50];
    int health;
    int strength;
    Room *current_room;
    char *inventory[INVENTORY_SIZE];
    int item_count;
}Player;

void initialize_player(Player *player, char *name);
void display_player_info(Player *player);
void pickup_item(Player *player, char *item);
void display_inventory(Player *player);
void move(Player *player, char *direction);
void look_items(Player *player);
void look_creature(Player *player);
void battle(Player *player, Creature *creature);
void clean_input(char *str);
#endif