
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creature.h"
#include "player.h"

Creature* create_creature(char *name, int health, int attack_power) {
    Creature *creature = malloc(sizeof(Creature));
    creature->name = strdup(name);
    creature->health = health;
    creature->attack_power = attack_power;
    return creature;
}

void display_creature(Creature *creature) {
    printf("Creature: %s\n", creature->name);
    printf("Health: %d\n", creature->health);
    printf("Attack Power: %d\n", creature->attack_power);
}

void attack_creature(Creature *creature, int damage) {
    creature->health -= damage;
    printf("%s took %d damage. Remaining health: %d\n", creature->name, damage, creature->health);
}
int is_creature_alive(Creature *creature) {
    return creature->health > 0;
}

void battle(Player *player, Creature *creature) {
    printf("A wild %s appears!\n", creature->name);
    while (player->health > 0 && is_creature_alive(creature)) {
        printf("You attack %s!\n", creature->name);
        attack_creature(creature, player->strength);
        
        // canavar hayattaysa saldıracak
        if (is_creature_alive(creature)) {
            printf("%s attacks you!\n", creature->name);
            player->health -= creature->attack_power;
            printf("You took %d damage. Remaining health: %d\n", creature->attack_power, player->health);
        }
    }

    if (player->health <= 0) {
        printf("You have been defeated by %s...\n", creature->name);
    } else {
        printf("You have defeated %s!\n", creature->name);
    }
}
