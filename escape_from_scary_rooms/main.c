#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "room.h"
#include "creature.h"
#include "player.h"

#define MAX_DESC_LENGTH 256

int main()
{
    char description[MAX_DESC_LENGTH];  
    Player player;
    char player_name[50];  

    printf("WELCOME TO 'ESCAPE FROM SCARY ROOMS' GAME\n");
    printf("------------------------------------------------------------\n");
    printf("        ROOM2\n");
    printf("          |\n");
    printf("          |\n");
    printf("          |\n");
    printf("          |\n");
    printf("          |\n");
    printf("        ROOM1------------>ROOM3------------>ROOM4\n");
    printf("------------------------------------------------------------\n");
    printf("\n");
    printf("              north\n");
    printf("                |\n");
    printf("        west----|----east\n");
    printf("                |\n");
    printf("              south\n");
    printf("------------------------------------------------------------\n");

    printf("Enter player name: ");
    fgets(player_name, sizeof(player_name), stdin);

    size_t len = strlen(player_name);
    if (len > 0 && player_name[len-1] == '\n') {
        player_name[len-1] = '\0';  // \n karakterini kaldırmak icin
    }

    initialize_player(&player, player_name);

    load_room_description("room1.txt", description);  
    Room *room1 = create_room(description);         
    add_item_room(room1, "Hand-saw");
    add_item_room(room1, "Magic Potion");

    
    load_room_description("room2.txt", description);
    Room *room2 = create_room(description);
    add_item_room(room2, "Surgery Set");
    add_item_room(room2, "Poisoned Injection");

    
    load_room_description("room3.txt", description);
    Room *room3 = create_room(description);
    add_item_room(room3, "Hunting Rifle");
    add_item_room(room3, "Necessary Documents");

    
    load_room_description("room4.txt", description);
    Room *room4 = create_room(description);
    add_item_room(room4, "Invisibility potion");


    room1->connections[0] = room2;
    room2->connections[1] = room1;
    room1->connections[2] = room3;
    room3->connections[3] = room1;
    room3->connections[2] = room4;
    room4->connections[3] = room3;

    player.current_room = room1;

    int number;
    char direction[5];

    printf("Welcome to the game, %s\n", player.name); // player pointer olmadigi icin name e "." ile ulastik.
                                                      // pointer olsaydi -> kullanacaktik.
    Creature *slenderman = create_creature("slenderman", 30, 5);
    add_creature_room(room1, slenderman);
    Creature *witcher = create_creature("Witcher", 20, 2);
    add_creature_room(room3, witcher);
    Creature *ancient_evil = create_creature("Ancient Evil Charles", 40, 10);
    add_creature_room(room2, ancient_evil);



    while (1)
    {
        printf("------------------------------------------------------------\n");
        printf("Enter number for command:\n1.LOOK\n2.MOVE DIRECTION\n3.GET ITEM\n4.PLAYER INVENTORY\n5.ATTACK\n6.EXIT\n ");
        printf("------------------------------------------------------------\n");
        
        scanf("%d", &number); // number pointer olmadığı için & ile çagirdik.

        switch (number)
        {
        case 1:
            look_items(&player);
            break;
        case 2:
            printf("Enter a direction (north/south/east/west): ");
            scanf("%s", direction);
            move(&player, direction);
            getchar();
            break;
        case 3:
            getchar();
            char item[30];
            printf("Enter item name: ");
            fgets(item, 30, stdin);
            clean_input(item);
            pickup_item(&player,item);
            break;
        case 4:
            display_inventory(&player);
            break;
        case 5:
            if (player.current_room->creature)
            {
                battle(&player, player.current_room->creature); // savası baslatır
            }
            else
            {
                printf("There is no creature here to fight.\n");
            }
            break;
        case 6:
            printf("EXITING the game. SEE YOU AGAIN!");
            return 0;
        default:
            printf("Unknown number for command. Available numbers: 1, 2, 3, 4, 5, 6\n");
            break;
        }
    }

    free_room(room1);
    free_room(room2);
    free_room(room3);
    free_room(room4);

    return 0;
}