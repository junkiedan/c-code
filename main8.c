#include <stdio.h>
#include <math.h>

int main() {
    double input;
    printf("Enter value: ");
    scanf("%lf", &input);
    printf("%lf\n", input);
    function(input);
    return 0;
}

int function(double x) {
    double res;
    if(x < 0) {
        res = -5 * x;
    } else if(x < 20) {
        res = 7 * pow(x, 2) + 16 * x;
    } else {
        res = 3 * sqrt(x) + 6;
    }
    printf("Result: %.15lf\n", res);
    return 0;
}