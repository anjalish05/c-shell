#include "headers.h"
// #include "echo.h"

// #include <stdio.h>
// #include <string.h>

// int main(int argc, char *argv[]) {
    

//     return 0;
// }

void echo(char *argv[], int argc) {
    
    // if (argc > 1) {
    //     // Start from the second argument (argv[1]) since the first argument is the command itself
    //     if(argv[1][0] == '"' && argv[argc-1][strlen(argv[1]) - 1] == '"') {
    //         for(int i = 1; i < argc; i++) {
    //             memmove(argv[i], argv[i] , strlen(argv[i]) - 2);
    //             argv[strlen(argv[i]) - 2] = '\0';
    //             printf("%s", argv[i]);
    //         }
    //     }
    //     else {
    //         for (int i = 1; i < argc; i++) {
            
    //             // Print the argument as it is
    //             if (i > 1) {
    //                 printf(" ");  // Add a space between arguments
    //             }
    //             printf("%s", argv[i]);
    //         }
    //     }

        
    //     printf("\n");

    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        // return 1;
    }

    int in_quotes = 0;
    for (int i = 1; i < argc; i++) {
        char *word = argv[i];
        // if(word[0] == '\"' && word[strlen(word) - 1] == '\"') {
        //     in_quotes = 1; 
        //     word[0] = '\0';
        //     word[strlen(word) - 1] = '\0';
        // }
        if (word[0] == '\"') {
            // If the word starts with a double quote, set in_quotes flag.
            in_quotes = 1;
            // Skip the opening double quote.
            word++;
        }  
        if (word[strlen(word) - 1] == '\"') {
            // If the word ends with a double quote, remove it.
            word[strlen(word) - 1] = '\0';
        }
        if (in_quotes) {

            if(i > 1) {
                printf(" ");
            }
            // If in quotes, print the word as it is without processing spaces/tabs.
            // if(word[i] == ' ' || word[i] == '\t')

            printf("%s", word);

        } 

        else {
            // Otherwise, process spaces and tabs.
            int word_length = strlen(word);
            
            for (int j = 0; j < word_length; j++) {

                if (word[j] != ' ' && word[j] != '\t') {
                    // If the character is not a space or tab, print it.
                    printf("%c", word[j]);
                } 
                // else if (j > 0 && (word[j - 1] != ' ' && word[j - 1] != '\t')) {
                //     // If the previous character was not a space or tab, print a single space.
                //     printf(" ");
                // }
            }
        }

        if (i < argc - 1) {
            // If in quotes and there are more words, print a space between them.
            printf(" ");
        }
    }

    printf("\n");
}
    // printf("\n");
// }
