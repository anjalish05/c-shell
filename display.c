#include "headers.h"

#define PATH_MAX 4096
#define MAX_INPUT_LENGTH 1024

char* get_username() {
    char *user = malloc(sizeof(char) * 1024);

    getlogin_r(user, sizeof(user));

    return user;
}

char* get_system_name() {
    char *host = malloc(sizeof(char) * 1024);
    gethostname(host, sizeof(host));
    
    return host; 
}

char* get_curr_dir() {
    char* buffer = malloc(PATH_MAX);
    if (buffer) {
        if (getcwd(buffer, PATH_MAX) != NULL) {
            return buffer;
        }
        free(buffer);  // Free the buffer if getcwd fails
    }
    return "unknown";
}

char* get_prompt() {
    char* username = get_username();
    char* system_name = get_system_name();
    char* curr_dir = get_curr_dir();

    char* prompt = malloc(MAX_INPUT_LENGTH);
    if (prompt) {
        snprintf(prompt, MAX_INPUT_LENGTH, "<%s@%s:%s> ", username, system_name, curr_dir);
        return prompt;
    }

    return "prompt_error";  // Memory allocation error
}