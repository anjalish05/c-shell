#include "headers.h"


int main() {

    while (1)
    {
        char *cmd = NULL; // command to read from standard inputs 
        char *cmd_cpy = NULL;  // copy of command
        char *token = NULL; // token to split my command
        char *delim = " \t\n\r"; // delimeter to split my command

        size_t n = 0; // size of buffer
        int argc = 0; // number of arguments
        int i = 0; // counter variable
        char **argv = NULL; // array of arguments
    
        printf("$ "); 
        if(getline(&cmd, &n, stdin) == -1) {
            return -1; // if getline fails to read from stdin (failure)
        }

        // argc = number of tokens that can be retrieved 

        cmd_cpy = strdup(cmd);

        token = strtok(cmd, delim); // first token

        while(token) {
            token = strtok(NULL, delim); 
            argc++; 
        }

        printf("%d\n", argc); 

        argv = malloc(sizeof(char *) * argc); // we currently have the array for which we've allocated the memory

        token = strtok(cmd_cpy, delim); // first token

        while(token) {
            argv[i] = token; 
            token = strtok(NULL, delim);
            i++; 
        }

        argv[i] = NULL; // final element 
        i = 0; 
        while(argv[i]) {
            printf("%s\n", argv[i++]); 
            // i++;
        }

        free(cmd), free(argv), free(cmd_cpy); 
    }

    return 0; 
}