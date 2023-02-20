/* William Zhang 251215208
The purpose of this program is to act as a database for creating and managing teams 
for the World Cup.
*/

#include <stdio.h>
#include <string.h>
//determine maximum teams
#define MAX_TEAMS 32
//shows the details of a team
struct Team {
    int code;
    char name[25];
    char seed[25];
    char kitColor;
} teams[MAX_TEAMS];

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

//gets user input data and stores it into a team
int teamGetter(struct Team teams[], int count) {
    //get code for team if within scope
    int code; 
    char kitColor;
    printf("Enter team code: ");
    scanf("%d", &code);
    if(code > 31 || code < 0){
        printf("Please enter a valid team code");
        return 0;
    }
    //loop through to see if the team already exists
    for(int teamPos = 0; teamPos < count; teamPos++) {
        if(teams[teamPos].code == code){
            printf("Team already exists");
            return 0;
        }
    }
    teams[count].code = code;
    //get name for team
    printf("Enter team name: ");
    scanf("%s", teams[count].name);
    //get group seeding for name if within scope
    printf("Enter group seeding: ");
    scanf("%s", teams[count].seed);
    if(teams[count].seed[0] < 'A' || teams[count].seed[0] > 'H' || teams[count].seed[1] < 49 || teams[count].seed[1] > 52) {
        printf("Please enter a valid group seeding");  
        return 0;
    }
    //get the color for the team if within scope
    printf("Enter the kit color: ");
    scanf(" %c", &kitColor);
    if(kitColor != 'R' && kitColor != 'O' && kitColor != 'Y' && kitColor != 'G' && kitColor != 'B' && kitColor != 'I' && kitColor != 'V') {
        printf("Please enter a valid color");   
        return 0;
    }
    teams[count].kitColor = kitColor;
    return 1;
}

//updates a team given by user input
void updateTeam(struct Team teams[], int count) {
    //get updated code for team 
    int code;
    printf("Enter team code: ");
    scanf("%d", &code);
    //loop through to see if the team already exists
    for(int teamPos = 0; teamPos < count; teamPos++) {
        char kitColor;
        if(teams[teamPos].code != code){
            printf("Team does not exist");
        }
        else {
        //if team does not exist, continue updating the team
        //get the team name
        printf("Enter team name: ");
        scanf("%s", teams[teamPos].name);
        //get the group seed if within scope
        printf("Enter group seeding: ");
        scanf("%s", teams[teamPos].seed);
        if(teams[teamPos].seed[0] < 'A' || teams[teamPos].seed[0] > 'H' || teams[teamPos].seed[1] < 49 || teams[teamPos].seed[1] > 52) {
            printf("Please enter a valid group seeding");  
            return;
        }
        //get the color if within scope
        printf("Enter the kit color: ");
        scanf(" %c", &kitColor);
        if(kitColor != 'R' && kitColor != 'O' && kitColor != 'Y' && kitColor != 'G' && kitColor != 'B' && kitColor != 'I' && kitColor != 'V') {
            printf("Please enter a valid color");   
            return;
        }
        teams[teamPos].kitColor = kitColor;
        }
    }
}

//finds a team based on the team code given
void findTeam(struct Team teams[], int count) {
    //get team code
    int code;
    printf("Enter team code: ");
    scanf("%d", &code);
    //loop through to see if the team exists
    for(int teamPos = 0; teamPos < count; teamPos++){
        if(teams[teamPos].code != code){
            printf("Team does not exist");
        }
        else {
        //if the team exists, print out its information
        printf("Team Code           Team Name                        Group Seeding          Primary Kit Color\n");
        printf("%-10d           %-19s             %-17.2s         %s\n", teams[teamPos].code, teams[teamPos].name, teams[teamPos].seed, getColor(teams[teamPos].kitColor));
        }
    }
}

//print out the team details
void printTeam(struct Team teams[MAX_TEAMS], int count) {
    printf("Team Code           Team Name                        Group Seeding          Primary Kit Color\n");
    //loop through to print each team and its corresponding information
    for(int teamPos = 0; teamPos < count; teamPos++){
        printf("%-10d           %-19s             %-17.2s         %s\n", teams[teamPos].code, teams[teamPos].name, teams[teamPos].seed, getColor(teams[teamPos].kitColor));
    }
}

//main method 
int main() {
    //set user inputs
    char userInput;
    int tally = 0;
    //header
    printf("****************************************\n");
    printf("*           2211 World cup             *\n");
    printf("****************************************\n");
    //while the user does not quit, continue to loop the program
    while (userInput != 'q'){
        //get user input
        printf("Enter operation code: ");
        scanf(" %c", &userInput);
        //switch case statement for each user input possibility
        switch(userInput){
            //recieve information on a new team
            case 'i':
                if (teamGetter(teams, tally)){
                    tally++;
                }
                break;
                //find a team 
            case 's':
                findTeam(teams, tally);
                break;
                //update a team
            case 'u':
                updateTeam(teams, tally);
                break;
                //print the teams
            case 'p':
                printTeam(teams, tally);
                break;
                //quit the program
            case 'q':
                break;
                //if none of the above, prompt user to re-select an option
            default:
                printf("Please select a valid input");
                break;
        }
        //spacing
        printf("\n");
    }
    return 0;
}