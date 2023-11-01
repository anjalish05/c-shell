#include "headers.h"
// #include "echo.h"

void echo(char *argv[], int argc) {
    
    if (argc > 1) {
        // Start from the second argument (argv[1]) since the first argument is the command itself
        if(argv[1][0] == '"' && argv[argc-1][strlen(argv[1]) - 1] == '"') {
            for(int i = 1; i < argc; i++) {
                memmove(argv[i], argv[i] , strlen(argv[i]) - 2);
                argv[strlen(argv[i]) - 2] = '\0';
                printf("%s", argv[i]);
            }
        }
        else {
            for (int i = 1; i < argc; i++) {
            
                // Print the argument as it is
                if (i > 1) {
                    printf(" ");  // Add a space between arguments
                }
                printf("%s", argv[i]);
            
            }
        }

        
        printf("\n");
    }
    // printf("\n");
}