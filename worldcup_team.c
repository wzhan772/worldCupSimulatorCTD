#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//include team header
#include "worldcup_team.h"
#define TeamNode struct TeamNode

//convertor for characters to colors when printing output
char* getColor(char c) {
    if(c == 'R') {
        return "Red";
    }
    else if(c == 'O') {
        return "Orange";
    }
    else if(c == 'Y') {
        return "Yellow";
    }
    else if(c == 'G') {
        return "Green";
    }
    else if(c == 'B') {
        return "Blue";
    }
    else if(c == 'I') {
        return "Indigo";
    }
    else if(c == 'V') {
        return "Violet";
    }
}

//print out one of the teams
void printTeam(TeamNode *team) {
    //print team specified
    printf("Team Code           Team Name                        Group Seeding          Primary Kit Color\n");
    printf("%-10d           %-19s             %-17.2s         %s\n", team->code, team->name, team->seed, getColor(team->kitColor));
}
//print out all of the teams
void printTeams(TeamNode *head) {
    printf("Team Code           Team Name                        Group Seeding          Primary Kit Color\n");
    //print each team
    for (TeamNode *point = head; point; point = point->nextNode)
        printf("%-10d           %-19s             %-17.2s         %s\n", point->code, point->name, point->seed, getColor(point->kitColor));
}

//function to add a team
void addTeam(TeamNode **head) {
    TeamNode *addedTeam = malloc(sizeof(TeamNode));
    //get user input
    printf("    Enter the team's code: ");
    scanf("%d", &addedTeam->code);
    //if the team already exists or team code is not valid, end program
    if (addedTeam->code < 0) {
        printf("Invalid team code\n");
        return;
    }
    else if (searchTeam(*head, addedTeam->code)) {
        printf("Team already exists in database.\n");
        return;
    }
    //read team name from user input
    printf("    Enter team name: ");
    scanf("%24s", &addedTeam->name);
    //look for team names that already exist
    for (TeamNode *exist = *head; exist; exist = exist->nextNode)
    {
        if (strcmp(exist->name, addedTeam->name) == 0)
        {
            printf("This team already exists\n", addedTeam->name);
            return;
        }
    }
    fflush(stdin);
    //get user input for team seed
    printf("    Enter team seed: ");
    scanf("%s", &addedTeam->seed);
    //see if seed is valid or not
    if (addedTeam->seed[0] < 'A' || addedTeam->seed[0] > 'H' || addedTeam->seed[1] > '4' || addedTeam->seed[1] < '1')
    {
        printf("Please enter a valid team seed\n");
        return;
    }
    //get the color for the team if within scope
    printf("    Enter team kit color: ");
    scanf("\n%c", &addedTeam->kitColor);
    //see if the color is valid or not
    if (addedTeam->kitColor != 'R' && addedTeam->kitColor != 'O' && addedTeam->kitColor != 'Y' && addedTeam->kitColor != 'G' && addedTeam->kitColor != 'B' && addedTeam->kitColor != 'I' && addedTeam->kitColor != 'V')
    {
        printf("Please enter a valid color\n");
        return;
    }
    //update linked list
    addedTeam->nextNode = *head;
    *head = addedTeam;
}

//function to update team
void updateTeam(TeamNode *head, int code) {
    TeamNode *team = searchTeam(head, code);
    //if the team exists, then proceed to update it
    if (team)
    {
        TeamNode *addedTeam = malloc(sizeof(TeamNode));
        //get user input for new team name
        printf("    Enter new team name: ");
        scanf("%24s", &addedTeam->name);
        //fflush old inputs
        fflush(stdin);
        //loop through and check to see if team already exists
        for (TeamNode *exist = head; exist; exist = exist->nextNode) {
            //if the user entered a name that already exists, do not update it
            if (team->code != exist->code && strcmp(exist->name, addedTeam->name) == 0) {
                printf("team name already exists, please select a different one", addedTeam->name);
                return;
            }
        }
        //get new seed for team
        printf("    Enter new team seed: ");
        //seed must be 2 characters long
        scanf("%2s", &addedTeam->seed);
        //get new team kit color
        printf("    Enter new kit color: ");
        // store the previous value of the kit color
        scanf("\n%c", &addedTeam->kitColor);
        if (addedTeam->kitColor != 'R' && addedTeam->kitColor != 'O' && addedTeam->kitColor != 'Y' && addedTeam->kitColor != 'G' && addedTeam->kitColor != 'B' && addedTeam->kitColor != 'I' && addedTeam->kitColor != 'V')
        {
            printf("Please enter a valid color\n");
            return;
        }
        //update team values
        strcpy(team->name, addedTeam->name);
        strcpy(team->seed, addedTeam->seed);
        //update kit color
        team->kitColor = addedTeam->kitColor;
    }
    //if the team does not exist
    else {
        //if team cannot be located print error message
        printf("Team cannot be found\n");
        return;
    }
}

//function to search for team
TeamNode *searchTeam(TeamNode *head, int code) {
    //loop through teams to search for specified team using code from user input
    for (TeamNode *search = head; search; search = search->nextNode) {
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

void deleteTeam(TeamNode **head, int code) {
    //if the team exists
    if (searchTeam(*head, code) != NULL) {
        TeamNode *current = *head, *previous = NULL;
        //loops until the current pointer hits NULL
        for (; current; previous = current, current = current->nextNode) {
            if (current->code == code) {
                break;
            }
        }
        if (previous == NULL) {
            //make new head of node
            *head = current->nextNode;
        } else if (current == NULL) {
            //stop program
            return;
        } else {
            //change node values
            previous->nextNode = current->nextNode;
        }
        //free memory
        free(current);
    }
    //if the team does not exist, print out error message
    else {
        printf("This team does not exist\n");
        return;
    }
}

