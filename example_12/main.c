#include <stdio.h>

int main() {
    int n, input;
    printf("Enter how many numbers will be entered: ");
    scanf("%d", &n);
    float sum = 0;
    for(int i = 0; i < n; i++) {
        printf("Enter number: ");
        scanf("%d", &input);
        while(input <= 0) {
            printf("Give a number greater than 0: ");
            scanf("%d", &input);
        } 
        sum += input;
    }
    printf("The average of the numbers that you entered is %.2f", sum/n);
    return 0;
}