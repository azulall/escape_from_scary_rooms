
#ifndef CREATURE_H
#define CREATURE_H

typedef struct Creature {
    char *name;
    int health;
    int attack_power;

} Creature;

Creature* create_creature(char *name, int health, int attack_power);
void display_creature(Creature *creature);
void attack_creature(Creature *creature, int damage);
int is_creature_alive(Creature *creature);

#endif
