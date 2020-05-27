#include <stdio.h>

int main() {
    float input = 1.0;
    int n = 0;
    while(input != 0) {
        if(input > 34) n++;
        printf("Enter a real number: ");
        scanf("%f", &input);
    }
    printf("You entered %d numbers greater than 34!", n);
    return 0;
}