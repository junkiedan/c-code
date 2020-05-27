#include <stdio.h>

int main() {
    printf("Enter kWh: ");
    int input;
    scanf("%d", &input);
    float bill = 40;
    if(input > -0.01 && input < 500) {
        bill += input * 0.02;
    } else if(input < 800) {
        bill += 500 * 0.02 + (input - 500) * 0.015;
    } else {
        bill += 500 * 0.02 + 300 * 0.015 + (input - 800) * 0.01;
    }
    printf("You have to pay %.2f euro!", bill);
    return 0;
}