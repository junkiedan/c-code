#include <stdio.h>
#include <string.h>
#define STR_MAX_RANGE 1024

int main() {
    char str[STR_MAX_RANGE];
    char delim[] = " ,-.'";
    int counter = 0;
    printf("Enter a big string: ");
    fgets(str, STR_MAX_RANGE, stdin);
    size_t length = strlen(str) - 1;
    char *ptr = strtok(str, delim);

    while(ptr != NULL) {
        ptr = strtok(NULL, delim);
        counter++;
    }

    printf("Inside the big string there are %d distinct words.\n", counter);

    return 0;
}
