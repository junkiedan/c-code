#include <stdio.h>
#include <math.h>

int main() {
    printf("Sum of 5*(i^2) is equal or more than 2000 when i = %d", sum(2000));
    return 0;
}

int sum(int limit) {
    float res = 0;
    int i = 1;
    while(res <= 2000) {
        res += 5 * pow(i, 2);
        i++;
    }
    return --i;
}