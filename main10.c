#include <stdio.h>

int main() {
    int numbers[100];
    for(int i = 0; i < 100; i++) {
        printf("Enter a value: ");
        scanf("%d", &numbers[i]);
    }
    print(numbers);
    findMin(numbers);
    odds(numbers);
    return 0;
}

int print(int *array) {
    printf("%d", array[0]);
    for(int i = 1; i < 100; i++) {
        printf(", %d", array[i]);
    }
    printf("\n");
    return 0;
}

int findMin(int *array) {
    int min = array[0];
    int pos = 0;
    for(int i = 0; i < 100; i++) {
        if(array[i] < min) {
            min = array[i];
            pos = i + 1;
        }
    }
    printf("Min number: [position: %d, value: %d].\n", pos, min);
    return 0;
}

int odds(int *array) {
    int n = 0;
    int temp[100];
    for(int i = 0; i < 100; i++) {
        if(array[i] < 0) temp[i] = -array[i];
        else temp[i] = array[i];
    }
    for(int i = 0; i < 100; i++) {
        if(temp[i] % 2 == 1) n++;
    }
    printf("There are %d odd numbers in the array.", n);
    return 0;
}