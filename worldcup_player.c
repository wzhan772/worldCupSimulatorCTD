#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//include other files
#include "worldcup_player.h"

//read team/player
char *inputStream()
{
    fflush(stdin);
    char *inputWord = malloc(sizeof(char) * 50);
    char input;
    int valid = 0;
    //make sure size is less than 50 characters long
    while (valid < 50 && (input = getchar()) != '\n') {
        *(inputWord + valid) = input;
        valid++;
    }
    *(inputWord + valid) = '\0';
    //loop through and clear
    while (input != '\n')
        input = getchar();
    return inputWord;
}

//print out player statistics
void printPlayer(PlayerNode *player)
{
    // print header and player info
    printf("Player Code           Player Name                        Player Age          Player Club\n");
    printf("%-10d            %-19s            %-17.2d        %s\n", player->code, player->name, player->age, player->club);
}

//print out all player statistics
void printPlayers(PlayerNode *head)
{
    printf("Player Code           Player Name                        Player Age          Player Club\n");

    // loop through all players
    for (PlayerNode *player = head; player; player = player->nextNode)
        printf("%-10d            %-19s            %-17.2d        %s\n", player->code, player->name, player->age, player->club);
}

//function to add a player
void addPlayer(PlayerNode **head)
{
    PlayerNode *playerAdded = malloc(sizeof(PlayerNode));
    //get user input
    printf("    Enter player code: ");
    scanf("%d", &playerAdded->code);
    //if the code already exists then stop the program
    if (playerAdded->code < 0) {
        printf("Player code is invalid\n");
        return;
    }
    else if (searchPlayer(*head, playerAdded->code)) {
        printf("This player already exists\n");
        return;
    }
    printf("    Enter player name: ");
    strcpy(playerAdded->name, inputStream());
    //fflush input stream
    fflush(stdin);
    //get the age of the player
    printf("    Enter the age of the player: ");
    scanf("%d", &playerAdded->age);
    //if the age is lower than 17 or greater than 99 then dont allow it to be added
    if (playerAdded->age < 17 || playerAdded->age > 99)
    {
        printf("Age is invalid\n");
        return;
    }
    printf("    Enter the associated club: ");
    strcpy(playerAdded->club, inputStream());
    //fflush input stream
    fflush(stdin);
    //update linked list
    playerAdded->nextNode = *head;
    *head = playerAdded;
}

//function updates a player
void updatePlayer(PlayerNode *head, int code) {
    PlayerNode *player = searchPlayer(head, code);
    //if the player exists, then proceed to update them
    if (player) {
        PlayerNode *addedPlayer = malloc(sizeof(PlayerNode));
        //get user input for new player name
        printf("    Enter the new name of the player: ");
        strcpy(addedPlayer->name, inputStream());
        fflush(stdin);
        //get new player age
        printf("    Enter the new age of the player: ");
        scanf("\n%d", &addedPlayer->age);
        //check to see if player age is valid or not
        if (addedPlayer->age < 17 || addedPlayer->age > 99) {
            printf("Age is invalid\n");
            return;
        }
        //get the new club name for the player specified
        printf("    Enter new club name for player: ");
        strcpy(addedPlayer->club, inputStream());
        //flush input stream
        fflush(stdin);
        //update player specifications
        strcpy(player->name, addedPlayer->name);
        player->age = addedPlayer->age;
        //update player club
        strcpy(player->club, addedPlayer->club);
    }
    //if the player cannot be found
    else {
        //print an error message
        printf("player with code %d cannot be found.\n");
        return;
    }
}

//function searches for a player
PlayerNode *searchPlayer(PlayerNode *head, int code)
{
    //loop through players to search for specified player using code from user input
    for (PlayerNode *search = head; search; search = search->nextNode) {
        //if team cannot be found return NULL
        if (search->code != code) {
            return NULL;
        }
            //if team can be found then return it
        else {
            return search;
        }
    }
}

//function deletes a player
void deletePlayer(PlayerNode **head, int code) {
    //checks if the player is in the database
    if (searchPlayer(*head, code) != NULL) {
        PlayerNode *current = *head, *previous = NULL;
        //loops until the current pointer hits NULL
        for (; current; previous = current, current = current->nextNode)
        {
            if (current->code == code) {
                break;
            }
        }
        if (previous == NULL)
        {
            //update head
            *head = current->nextNode;
        }
        else if (current == NULL) {
            //stop program if head is null
            return;
        }
        else {
            //update next values for nodes
            previous->nextNode = current->nextNode;
        }
        free(current);
    }
    //if the player already exists
    else {
        //print error message
        printf("player already exists\n");
        return;
    }

}
