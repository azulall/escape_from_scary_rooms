#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "room.h"
#include "player.h"

void initialize_player(Player *player, char *name)
{
    strncpy(player->name, name, sizeof(player->name));
    player->health = 100;
    player->strength = 10;
    player->item_count = 0;
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        player->inventory[i] = NULL;
    }
}

void display_player_info(Player *player)
{
    printf("Player name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Strength: %d\n", player->strength);
}

void pickup_item(Player *player,char *item) {
    Room *current_room = player->current_room; 

    int found = 0;
    for (int i = 0; i < current_room->item_count; i++) {
        if (strcmp(current_room->items[i], item) == 0) {
            found = 1;

            
            if (player->item_count == INVENTORY_SIZE) {
                printf("Inventory capacity has been reached. No more items can be added!\n");
                return;
            }

            
            player->inventory[player->item_count] = strdup(item);
            player->item_count++;
            printf("Picked up: %s\n", item);
            printf("%s added to your inventory!\n", item);
            
            for (int j = i; j < current_room->item_count - 1; j++) {
                current_room->items[j] = current_room->items[j + 1];
            }
            current_room->items[current_room->item_count - 1] = NULL; 
            current_room->item_count--;
            return;
        }
    }
    if (!found) {
        printf("The item '%s' is not in this room!\n", item);
    }
}

void clean_input(char *str) {
    // Fazladan \n karakterini temizle
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void display_inventory(Player *player)
{
    printf("Inventory:\n");
    for (int i = 0; i < player->item_count; i++)
    {
        printf("%d. %s\n", i + 1, player->inventory[i]);
    }
    if (player->item_count == 0)
    {
        printf("Inventory is empty.\n");
    }
}

void move(Player *player, char *direction)
{
    int index_of_direction = -1;

    if (strcmp(direction, "north") == 0)
    {
        index_of_direction = 0;
    }
    else if (strcmp(direction, "south") == 0)
    {
        index_of_direction = 1;
    }
    else if (strcmp(direction, "east") == 0)
    {
        index_of_direction = 2;
    }
    else if (strcmp(direction, "west") == 0)
    {
        index_of_direction = 3;
    }
    else
    {
        printf("Invalid direction!\n");
    }

    if (player->current_room->connections[index_of_direction] != NULL)
    {
        player->current_room = player->current_room->connections[index_of_direction];

        printf("*%s\n", player->current_room->description);
        printf("Items in the room:\n");

        for (int i = 0; i < player->current_room->item_count; i++)
        {
            printf("%d. %s\n", i + 1, player->current_room->items[i]);
        }
    }
    else
    {
        printf("You cannot go that way!\n");
    }
}

void look_items(Player *player)
{
    printf("*%s\n", player->current_room->description);
    printf("Items in the room:\n");

    for (int i = 0; i < player->current_room->item_count; i++)
    {
        printf("%d. %s\n", i + 1, player->current_room->items[i]);
    }
}