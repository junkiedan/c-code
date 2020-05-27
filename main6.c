#include <stdio.h>
#include <math.h>

int main() {
    printf("###STEP = 1\n\n");
    function(1.0);
    printf("\n\n###STEP = 0.2\n\n");
    function(0.2);
    return 0;
}

int function(double d) {
    for(double i = 1; i <= 20; i+=d){
        printf("F(%.1lf) = %.15lf\n", i, exp(-5 * i) * cos(0.2 + 4 * i));
    }
    return 0;
}