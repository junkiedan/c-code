#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define VAL 5
#define MAX_NAME_SZ 256

void fill(char a1[VAL][MAX_NAME_SZ], float a2[VAL]);
void print(char a1[VAL][MAX_NAME_SZ], float a2[VAL]);
int findBest(float a[VAL]);
void printGood(char a1[VAL][MAX_NAME_SZ], float a2[VAL]);
void notPass(float a2[VAL]);
void averageGrade(float a2[VAL]);
void averageGradePass(float a2[VAL]);

int main() {
    char onoma[VAL][MAX_NAME_SZ];
    float bathmos[VAL];
    fill(onoma, bathmos);
    printf("\nSTUDENTS LIST:\n");
    print(onoma, bathmos);
    printf("\n");
    int posMax = findBest(bathmos);
    printf("Best: [Name: %s, Grades: %.1f]\n", onoma[posMax], bathmos[posMax]);
    printf("\n");
    printGood(onoma, bathmos);
    printf("\n");
    notPass(bathmos);
    printf("\n");
    averageGrade(bathmos);
    printf("\n");
    averageGradePass(bathmos);
    return 0;
}

void fill(char a1[VAL][MAX_NAME_SZ], float a2[VAL]) {
    char str_f[20];
    for(int i = 0; i < VAL; i++) {
        printf("Enter student's name: ");
        fgets(a1[i], MAX_NAME_SZ, stdin);
        if ((strlen(a1[i]) > 0) && (a1[i][strlen (a1[i]) - 1] == '\n')) a1[i][strlen (a1[i]) - 1] = '\0';
        printf("Enter student's grades: ");
        fgets (str_f, 20, stdin);
        if ((strlen(str_f) > 0) && (str_f[strlen (str_f) - 1] == '\n')) str_f[strlen (str_f) - 1] = '\0';
        a2[i] = strtof(str_f, NULL);
    }
}

void print(char a1[VAL][MAX_NAME_SZ], float a2[VAL]) {
    for(int i = 0; i < VAL; i++) {
        printf("[Name: %s, Grades: %.1f]\n", a1[i], a2[i]);
    }
}

int findBest(float a[VAL]) {
    int max = a[0];
    int pos = 0;
    for(int i = 0; i < VAL; i++) {
        if(a[i] > max) {
            max = a[i];
            pos = i;
        }
    }
    return pos;
}

void printGood(char a1[VAL][MAX_NAME_SZ], float a2[VAL]) {
    printf("Students with grades >= 6.5:\n");
    for(int i = 0; i < VAL; i++) {
        if(a2[i] > 6.49) printf("[Name: %s, Grades: %.1f]\n", a1[i], a2[i]);
    }
}

void notPass(float a2[VAL]) {
    printf("Number of students with grades < 5.0 (DID NOT PASS): ");
    int n = 0;
    for(int i = 0; i < VAL; i++) {
        if(a2[i] < 5.0) n++;
    }
    printf("%d\n", n);
}

void averageGrade(float a2[VAL]) {
    float sum = 0.0;
    for(int i = 0; i < VAL; i++) {
        sum += a2[i];
    }
    printf("The average student score is: %.1f\n", sum/VAL);
}

void averageGradePass(float a2[VAL]) {
    float sum = 0.0;
    int val = 0;
    for(int i = 0; i < VAL; i++) {
        if(a2[i] > 4.9) {
            sum += a2[i];
            val++;
        }
    }
    printf("The average passed student score is: %.1f\n", sum/val);
}