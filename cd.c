#include "headers.h"

#define PATH_MAX 4096
static char previous_dir[PATH_MAX];

void cd_command(char *dir) {

    if (dir == NULL) {
        // No argument provided, go to home directory
        char* home_dir = getenv("HOME");
        if (chdir(home_dir) != 0) {
            perror("shell");
        }
    } 
    
    else if (strcmp(dir, "-") == 0) {
        // print the previous directory
        // char* prev_dir = getenv(get_curr_dir());
        // char* temp = get_curr_dir();
        // if (prev_dir != NULL) {
        //     printf("%s\n", prev_dir);
        //     strcpy(prev_dir, temp); // Update previous directory

        //     free(temp);
        // } 
        // else {
        //     printf("No previous directory\n");
        // }
        // Go to the previous directory
        char* prev_dir = getenv("OLDPWD");
        if (prev_dir != NULL && chdir(prev_dir) != 0) {
            perror("shell");
        }
        if (prev_dir[0] != '\0') {
            char* temp = get_curr_dir(); // Store current directory
            if (chdir(prev_dir) != 0) {
                perror("shell");
            }
            
            printf("%s\n", prev_dir); // Print previous directory
            strcpy(previous_dir, temp); // Update previous directory
            free(temp);
        } 
        else {
            fprintf(stderr, "No previous directory\n");
        }
    } 
    
    else if (strcmp(dir, "~") == 0) {
        // Go to the home directory
        char* home_dir = getenv("HOME");
        if (chdir(home_dir) != 0) {
            perror("shell");
        }
    } 

    else if (strcmp(dir, "..") == 0) {
        // shift one level above the current directory 
        char parent_dir[PATH_MAX];

        if (getcwd(parent_dir, PATH_MAX) != NULL) {
            char* last_slash = strrchr(parent_dir, '/');
            if (last_slash != NULL) {
                *last_slash = '\0';
            }

            if (chdir(parent_dir) != 0) {
                perror("shell");
            }
        } 
        
        else {
            perror("shell");
        }
    }
    
    else {
        // Change to the specified directory
        if (chdir(dir) != 0) {
            perror("shell");
        }
    }
}

// int main(int argc, char *argv[]) {
//     if (argc == 1) {
//         cd_command(NULL);
//     } 
    
//     else if (argc == 2) {
//         cd_command(argv[1]);
//     } 
    
//     else {
//         printf("cd: too many arguments\n");
//     }

//     return 0;
// }