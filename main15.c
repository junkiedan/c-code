#include <stdio.h>
#include <stdlib.h>
#define CITIES 10
#define DAYS 30
#define MAX_NAME_SZ 256

void fill(char a[CITIES][MAX_NAME_SZ],int b[CITIES][DAYS]);
void print(char a[CITIES][MAX_NAME_SZ]);
void print2d(int a[CITIES][DAYS]);
void averageMonthTemp(char a[CITIES][MAX_NAME_SZ], int b[CITIES][DAYS], float c[CITIES]);
void lessThanAverage(char a[CITIES][MAX_NAME_SZ], int b[CITIES][DAYS], float c[CITIES]);
void maxDailyTemp(char a[CITIES][MAX_NAME_SZ], int b[CITIES][DAYS], int c[CITIES]);
void citiesDailyMaxTemp(char a[CITIES][MAX_NAME_SZ], int b[CITIES][DAYS], int c[CITIES]);

int main() {
    char cities[CITIES][MAX_NAME_SZ];
    int temperatures[CITIES][DAYS];
    float averageTemps[CITIES];
    int maxTemps[CITIES];
    fill(cities, temperatures);
    // print(cities);
    // print2d(temperatures);
    printf("\n");
    averageMonthTemp(cities, temperatures, averageTemps);
    printf("\n");
    lessThanAverage(cities, temperatures, averageTemps);
    printf("\n");
    maxDailyTemp(cities, temperatures, maxTemps);
    printf("\n");
    citiesDailyMaxTemp(cities, temperatures, maxTemps);
    return 0;
}

void fill(char a[CITIES][MAX_NAME_SZ],int b[CITIES][DAYS]) {
    char str_f[MAX_NAME_SZ];
    for(int i = 0; i < CITIES; i++) {
        printf("Enter city name: ");
        fgets(a[i], MAX_NAME_SZ, stdin);
        if ((strlen(a[i]) > 0) && (a[i][strlen (a[i]) - 1] == '\n')) a[i][strlen (a[i]) - 1] = '\0';
        for(int j = 0; j < DAYS; j++) {
            printf("City %s - Day %d - Tempereture: ", a[i], j + 1);
            fgets(str_f, MAX_NAME_SZ, stdin);
            b[i][j] = strtof(str_f, NULL);
        }
    }
}

void print(char a[CITIES][MAX_NAME_SZ]) {
    for(int i = 0; i < CITIES; i++) {
        printf("%s\n", a[i]);
    }
}

void print2d(int a[CITIES][DAYS]) {
    for(int i = 0; i < CITIES; i++) {
        for(int j = 0; j < DAYS; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void averageMonthTemp(char a[CITIES][MAX_NAME_SZ], int b[CITIES][DAYS], float c[CITIES]) {
    for(int i = 0; i < CITIES; i++) {
        int sum = 0;
        for(int j = 0; j < DAYS; j++) {
            sum += b[i][j];
        }
        c[i] = (float) sum / DAYS;
        printf("[City: %s, Average Temperature: %.2f]\n", a[i], c[i]);
    }
}

void lessThanAverage(char a[CITIES][MAX_NAME_SZ], int b[CITIES][DAYS], float c[CITIES]) {
    for(int i = 0; i < CITIES; i++) {
        int n = 0;
        for(int j = 0; j < DAYS; j++) {
            if((float)b[i][j] < c[i]) n++;
        }
        printf("City %s - %d days less than average temperature!\n", a[i], n);
    }
}

void maxDailyTemp(char a[CITIES][MAX_NAME_SZ], int b[CITIES][DAYS], int c[CITIES]) {
    for(int j = 0; j < DAYS; j++) {
        int max = b[0][j];
        int pos = 0;
        for(int i = 0; i < CITIES; i++) {
            if(b[i][j] > max) {
                max = b[i][j];
                pos = i;
            }
        }
        c[j] = max;
        printf("Day %d - Max temperature in City: %s - Value: %d!\n", j + 1, a[pos], c[j]);
    }
}

void citiesDailyMaxTemp(char a[CITIES][MAX_NAME_SZ], int b[CITIES][DAYS], int c[CITIES]) {
    for(int j = 0; j < DAYS; j++) {
        printf("Day %d - Max Temperature Value: %d\n###CITIES:\n", j + 1, c[j]);
        int n = 0;
        for(int i = 0; i < CITIES; i++) {
            if(b[i][j] == c[j]) {
                n++;
                printf("\t%s\n", a[i]);
            }
        }
        printf("Max Temperature on %d cities!\n\n", n);
    }
}

