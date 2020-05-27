#include <stdio.h>
#include <stdlib.h>
#define MONTHS 12
#define APPARTMENTS 10
#define MAX_NAME_SZ 256

void fill(int a[APPARTMENTS][MONTHS]);
void print2d(int a[APPARTMENTS][MONTHS]);
void calcAnnualConsumption(int a1[APPARTMENTS][MONTHS], int a2[APPARTMENTS]);
void print(int a[APPARTMENTS]);
void calcMinCons(int a[APPARTMENTS]);
void calcMaxMonthCons(int a[APPARTMENTS][MONTHS]);
void graphMonthCons(int a[APPARTMENTS][MONTHS]);
void swap(int* a, int* b);
void bubbleSort(int a[APPARTMENTS][MONTHS]);

int main() {
    int consumption[APPARTMENTS][MONTHS];
    int annualConsumption[APPARTMENTS];
    fill(consumption);
    printf("\n");
    calcAnnualConsumption(consumption, annualConsumption);
    printf("\nANNUAL CONSUMPTIONS:\n");
    print(annualConsumption);
    printf("\n");
    calcMinCons(annualConsumption);
    printf("\n");
    calcMaxMonthCons(consumption);
    printf("\n");
    graphMonthCons(consumption);
    return 0;
}

void fill(int a[APPARTMENTS][MONTHS]) {
    char str_f[20];
    for(int i = 0; i < APPARTMENTS; i++) {
        for(int j = 0; j < MONTHS; j++) {
            printf("Consumption for Appartment %d, Month %d: ", i + 1, j + 1);
            fgets(str_f, MAX_NAME_SZ, stdin);
            a[i][j] = strtof(str_f, NULL);
        }
    }
}

void print2d(int a[APPARTMENTS][MONTHS]) {
    for(int i = 0; i < APPARTMENTS; i++) {
        for(int j = 0; j < MONTHS; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void calcAnnualConsumption(int a1[APPARTMENTS][MONTHS], int a2[APPARTMENTS]) {
    for(int i = 0; i < APPARTMENTS; i++) {
        int ac = 0;
        for(int j = 0; j < MONTHS; j++) {
            ac += a1[i][j];
        }
        a2[i] = ac;
    }
}

void print(int a[APPARTMENTS]) {
    for(int i = 0; i < APPARTMENTS; i++) {
        printf("Appartment %d consumpted %d in one year.\n", i + 1, a[i]);
    }
}

void calcMinCons(int a[APPARTMENTS]) {
    int min = a[0];
    int pos = 1;
    for(int i = 0; i < APPARTMENTS; i++) {
        if(a[i] < min) {
            min = a[i];
            pos = i + 1;
        }
    }
    printf("Appartment %d had the minimum annual consumption: %d.\n", pos, min);
}

void calcMaxMonthCons(int a[APPARTMENTS][MONTHS]) {
    for(int i = 0; i < MONTHS;  i++) {
        int max = a[0][i];
        int pos = 1;
        for(int j = 0; j < APPARTMENTS; j++) {
            if(a[j][i] > max) {
                max = a[j][i];
                pos = j + 1;
            }
        }
        printf("Month %d - Highest consumption: %d from Appartment %d!\n", i + 1, max, pos);
    }
}

void graphMonthCons(int a[APPARTMENTS][MONTHS]) {
    int temp[APPARTMENTS][MONTHS];
    for(int i = 0; i < APPARTMENTS; i++) {
        for(int j = 0; j < MONTHS; j++) {
            temp[i][j] = a[i][j];
        }
    }
    bubbleSort(temp);
    for(int i = 0; i < MONTHS; i++) {
        printf("Month %d consumptions (Ascending Order): \n", i + 1);
        int max = temp[APPARTMENTS - 1][i], n = 0;
        for(int j = 0; j < APPARTMENTS; j++) {
            printf("%d ", temp[j][i]);
            if(temp[j][i] == max) n++;
        }
        printf("Month %d - %d Appartments had Max Consumption (value: %d)!\n", i + 1, n, max);
        printf("\n");
    }
}

void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void bubbleSort(int a[APPARTMENTS][MONTHS]) { 
   for (int i = 0; i < MONTHS; i++) {
       for (int j = 0; j < APPARTMENTS; j++) {
           for(int k = 0; k < APPARTMENTS - j - 1; k++) {
               if(a[k][i] > a[k + 1][i]) {
                   swap(&a[k][i], &a[k + 1][i]);
               }
           }
       }    
   }        
} 