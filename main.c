#include "headers.h"

#define PATH_MAX 4096
#define MAX_INPUT_LENGTH 1024


int main() {

    char input[MAX_INPUT_LENGTH];
    char *args[MAX_INPUT_LENGTH / 2 + 1];

    while (1) {

        char *prompt = get_prompt();
        printf("%s", prompt);

        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
            break;
        }

        char *token = strtok(input, " \t\n");
        int i = 0;
        while (token != NULL) {
            args[i] = token;
            token = strtok(NULL, " \t\n");
            i++;
        }
        args[i] = NULL;

        input[strcspn(input, "\n")] = '\0';

        if (input == NULL) {
            continue;
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }

        else if(strncmp(input, "echo", 4) == 0) {
            int argc = 0;
            while(args[argc] != NULL) {
                argc++;
            }
            if(argc > 1)
                echo(args, argc);
        }

        else if(strcmp(input, "pwd") == 0) {
            pwd(); 
        }

        else if(strncmp(input, "cd", 3) == 0) {
            char *dir = input + 3; // Extract the directory argument 
            cd_command(dir); 
        }
        // else if(strcmp(input, "history") == 0) {
        //     history(input); 
        // }

        else {
            printf("Command not found\n");
        }

        // Remove the trailing newline character from user input
        input[strcspn(input, "\n")] = '\0';

        // free(prompt);
    }

    return 0;
}