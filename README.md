# worldCupSimulatorCTD
An adaptation of the previous World Cup simulator with additional features

Design
As before, each election team will be stored as a structure with the following attributes:

Team code (eg. 0, 1, 2, 3, 4, etc.)
Each team code must be unique. There is no limit to the number of teams but each code will be greater than or equal to 0
Team name (eg. "Australia", "Cameroon", "Canada", "Argentina", "Belgium", etc.)
Only team names up to 25 characters in length are acceptable (including the null character - So think of this as 24+1). Each team name must be unique
Group seeding (eg. "A1", "B3", "F2", etc.)
Only groups A-H and seeds 1-4 are acceptable. (So only A1, A2, A3, A4, B1, B2, ..., H3, H4). Each group seeding must be unique
Primary kit (uniform) colours (eg. "Red", "Orange", "Yellow", "Green", "Blue", "Indigo", and "Violet")
Only the values "R", "O", "Y", "G", "B", "I", "V" are acceptable.
Now, you will also need to store each team's player as a structure with the following attributes:

Player code (eg. 0, 1, 2, 3, 4, etc.)
Each player code must be unique. There is no limit to the number of players but each code will be greater than or equal to 0
Player name (eg. "John Smith", "Jane Doe", etc.)
Only names up to 50 characters in length are acceptable (including the null character - So think of this as 49+1)
Player age (eg. 17, 18, 19, 20, etc.)
Only integers 17-99 are acceptable
Professional club affiliation (eg. "Manchester City", "Los Angeles FC", "Toronto FC", "AFC Ajax", etc.)
Only names up to 50 characters in length are acceptable (including the null character - So think of this as 49+1)
Your program will then use a linked list of structures to represent all teams and a linked list of structures to represent all players.

Implementation
Your program should continuously prompt the user for one of four possible commands:

Print help (using command h)
Print a simple message or messages describing how to use the program.
Quit (using command q)
Quit the program. Yes, all data is lost when quitting your program. You do not need to maintain the data across multiple runs.
Control teams (using command t)
See below
Control players (using command p)
See below
Teams
As in worldCupDB.c (Assignment 4) all the same commands exist as before:

Insert a new team (using command i)
Prompt the user for the team code
Assume the user will enter one integer
This must be unique in your database and cannot conflict with an existing team code. If there is a conflict with an existing code, or if the database is full (you cannot allocate any more memory), tell the user the error. The user can try again or you can return the user to the main prompt
Prompt the user for the name of the team
Assume the user will enter a string of characters of any length
If the team name is longer than the acceptable length, you should accept as many characters as you can and ignore any additional characters. If there is any other issue, tell the user the error. The user can try again or you can return the user to the main prompt
Prompt the user for the group seeding of the team
Assume the user will enter two characters: a letter representing the group, and a number representing the seeding
If the letter is not A-H or if the number is not 1-4, tell the user the error. The user can try again or you can return the user to the main prompt
Prompt the user for the area of the primary kit (uniform) colour
Assume the user will enter one character value
If the character is not in the list "R", "O", "Y", "G", "B", "I", or "V", tell the user the error. The user can try again or you can return the user to the main prompt
Search for an team in the database and print it out (using command s)
Prompt the user for the team code
If the team code is found, print out all the values for this team only (see the print command below for more details)
If the team code is not found, tell the user the error. The user can try again or you can return the user to the main prompt
Update a team in the database (using command u)
Prompt the user for the team code
If the team code is found, prompt the user to update all the values for the team (see the insert command above for details)
If the team code is not found, tell the user the error. The user can try again or you can return the user to the main prompt
Print the entire list of teams (using command p)
Print out a table listing all the teams in your database with all the attributes:
Team Code
Team Name
Group Seeding
Primary Kit Colour
You should implement one additional command:

Delete team (using command d)
Prompt the user for the team code
If the team code is found, delete the team safely by removing the element from the linked list and freeing the memory
If the team code is not found, tell the user the error. The user can try again or you can return the user to the main prompt
Players
Implement the following commands:

Insert a new player (using command i)
Prompt the user for the player code
Assume the user will enter one integer
This must be unique in your database and cannot conflict with an existing player code. If there is a conflict with an existing code, or if the database is full (you cannot allocate any more memory), tell the user the error. The user can try again or you can return the user to the main prompt
Prompt the user for the name of the player
Assume the user will enter a string of characters of any length
If the player name is longer than the acceptable length, you should accept as many characters as you can and ignore any additional characters. If there is any other issue, tell the user the error. The user can try again or you can return the user to the main prompt
Prompt the user for the age of the player
Assume the user will enter one integer
If the number is less than 17 or greater than 99, tell the user the error. The user can try again or you can return the user to the main prompt
Prompt the user for the professional club affiliation of the player
Assume the user will enter a string of characters of any length
If the professional club affiliation name is longer than the acceptable length, you should accept as many characters as you can and ignore any additional characters. If there is any other issue, tell the user the error. The user can try again or you can return the user to the main prompt
Search for a player in the database and print it out (using command s)
Prompt the user for the player code
If the player code is found, print out all the values for this player only (see the print command below for more details)
If the player code is not found, tell the user the error. The user can try again or you can return the user to the main prompt
Update a player in the database (using command u)
Prompt the user for the player code
If the player code is found, prompt the user to update all the values for the player (see the insert command above for details)
If the player code is not found, tell the user the error. The user can try again or you can return the user to the main prompt
Print the entire list of players (using command p)
Print out a table listing all the players in your database with all the attributes:
Player Code
Player Name
Age
Club
Delete player (using command d)
Prompt the user for the player code
If the player code is found, erase the player safely by removing the element from the linked list and freeing the memory
If the player code is not found, tell the user the error. The user can try again or you can return the user to the main prompt
