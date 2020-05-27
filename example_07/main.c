#include <stdio.h>
#include <math.h>

int main() {
    printf("The sum of N values will be calculated. Enter the n value: ");
    int input;
    scanf("%d", &input);
    printf("You entered %d.\n", input);
    function(input);
    return 0;
}

int function(int n) {
    double res = 0;
    for(double i = 1; i <= n; i++) {
        res += pow(1.0/i, 2.0);
    }
    printf("Result: %.15lf\n", res);
    return 0;
}