// sources:
// https://cboard.cprogramming.com/c-programming/62595-how-get-system-date.html

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>

// to return a string in c, use pointer
char *getCurrDir() {

    char currDir[1024];

    if(getcwd(currDir, sizeof(currDir)) != NULL) {
        //printf("Current Directory: %s\n", currDir);
        return currDir;
    }

    return "getcwd() error";
}

// display help commands
void printHelp() {
    printf("For more information on a specific command, type HELP command-name");
    printf("\nCD          Displays the name of or changes the current directory.");
    printf("\nCHDIR       Changes the current directory.");
    printf("\nCLS         Clears the screen.");
    printf("\nCMD         Starts a new instance of command interpreter.");
    printf("\nCOPY        Copies one or more files to another location.");
    printf("\nDATE        Display or sets the date.");
    printf("\nDEL         Deletes one or more files.");
    printf("\nDIR         Displays a list of files and subdirectories in a directory.");
    printf("\nMKDIR       Creates a directory.");
    printf("\nMOVE        Moves one or more files from one directory to another directory.");
    printf("\nRENAME      Renames a file or files.");
    printf("\nRMDIR       Removes a directory.");
    printf("\nTIME        Displays or sets the system time.");
    printf("\nTYPE        Displays the contents of a text file.");
    printf("\n\n");
    printf("For more information on tools see the original command prompt in your OS.\n\n");
}

// print not recognizable command
void notRecognized(char * command) {
    printf("'%s' ", command);
    printf("is not recognized as an internal or external command, operable program or batch file.\n\n");
}

// print current working directory
void printCurrDir() {
    char currDir[1024];

    if(getcwd(currDir, sizeof(currDir)) != NULL) {
        printf("%s\n\n", currDir);
    } else {
        perror("getcwd() error");
    }
}

// print list of files in the current directory
void printDir() {
    system("dir");
    printf("\n");
}

// print current time
void printTime() {
    time_t currTime = time(NULL);
    struct tm *t = localtime(&currTime);

    printf("The current time is: %d:%d:%d\n\n", t->tm_hour, t->tm_min, t->tm_sec);
}

// print current date
void printDate() {
    char date[9];

    _strdate(date);
    printf("The current date is: %s\n\n", date);

}

// print cmd
void printCmd() {
    system("cmd");
    printf("\n");
}

int main() {

    char user_command[50];
    int break_ = 1;

    do {
        // first, display the current working directory of the user
        printf(getCurrDir());
        printf(">");

        // wait for user input
        scanf("%s", user_command);


        // if user_command is equals to "help" or "HELP" (strcmp function was used)
        if(strcmp(user_command, "cd") == 0 || strcmp(user_command, "CD") == 0) {
            printCurrDir();
        } else if(strcmp(user_command, "dir") == 0 || strcmp(user_command, "DIR") == 0) {
            printDir();
        } else if(strcmp(user_command, "cmd") == 0 || strcmp(user_command, "CMD") == 0) {
            printCmd();
        } else if(strcmp(user_command, "date") == 0 || strcmp(user_command, "DATE") == 0){
            printDate();
        } else if(strcmp(user_command, "time") == 0 || strcmp(user_command, "TIME") == 0){
            printTime();
        } else if(strcmp(user_command, "help") == 0 || strcmp(user_command, "HELP") == 0) {
            printHelp(); // call printHelp function
        } else if(strcmp(user_command, "exit") == 0 || strcmp(user_command, "EXIT") == 0) {
            break_ = 0; // set break to 0, to stop loop
        } else {
            notRecognized(user_command); //
        }

    } while(break_ != 0); // end of while loop

    return 0;
}
