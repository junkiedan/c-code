#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MATRIX_SIZE 8

void printArray(int (*matrix)[MATRIX_SIZE]);
void fillArray(int matrix[MATRIX_SIZE][MATRIX_SIZE]);
void findMinimum(int matrix[MATRIX_SIZE][MATRIX_SIZE]);
void findMaximum(int matrix[MATRIX_SIZE][MATRIX_SIZE]);

int main() {
    // Εάν δεν δίνω κάθε φορά διαφορετικό seed στην ψευδοτυχαία γεννήτρια αριθμών θα μου δίνει
    // συνέχει τους ίδιους αριθμούς. Οπότε με την εντολή srand(time(NULL)) διασφαλίζω ότι παίρνω
    // διαφορετικούς τυχαίους αριθμούς κάθε φορά που τρέχω το πρόγραμμα
    srand(time(NULL));
    printf("Matrix size is %d\n\n", MATRIX_SIZE);
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    fillArray(matrix);
    printArray(matrix);
    printf("\n");
    findMinimum(matrix);
    printf("\n");
    findMaximum(matrix);
    return 0;
}

/*
    Εδώ κάνω τις κλείσεις στα πάντα χρησιμοποιώντας pointers.
*/

void printArray(int (*matrix)[MATRIX_SIZE]) {
    int i, j;
    for(i = 0; i < MATRIX_SIZE; i++) {
        for(j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

/*
    Εδώ κάνω τις κλείσεις στα πάντα χωρίς να χρησιμοποιήσω pointers.
    Όμως γενικά ισχύει ότι: matrix[i][j] είναι το ίδιο με το να γράψω *(*(matrix + i) + j)
    Όπως και: matrix[MATRIX_SIZE][MATRIX_SIZE] είναι το ίδιο με το να γράψω (*matrix)[MATRIX_SIZE]
*/

void fillArray(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    int i, j;
    for(i = 0; i < MATRIX_SIZE; i++) {
        for(j = 0; j < MATRIX_SIZE; j++) {
            // Το rand() μου δίνει έναν τυχαίο integer στο διάστημα [0, 32767] κάνοντας την πράξη
            // rand() mod n, μου δίνει έναν ακέραιο στο διάστημα [0, n-1]
            matrix[i][j] = rand() % MATRIX_SIZE;
        }
    }
}

/*
    Την εύρεση min & max τις κάνω με τον πιο απλό τρόπο. Στην περίπτωση του μικρότερου βάζω έναν
    μεγάλο αριθμό για αρχική τιμή ως μικρότερο και μετά το συγκρίνω με όλα τα στοιχεία της σειράς.
    Αντίστοιχα στην περίπτωση του μεγαλύτεου βάζω ως μεγαλύτερο το 0 και το συγκρίνω με τα υπόλοιπα.
*/

void findMinimum(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    int i, j, min, indexOfMin;
    for(i = 0; i < MATRIX_SIZE; i++) {
        min = MATRIX_SIZE;
        indexOfMin = 0;
        for(j = 0; j < MATRIX_SIZE; j++) {
            if(matrix[i][j] < min) {
                min = matrix[i][j];
                indexOfMin = j;
            }
        }
        printf("Minimum number on row #%d is on column #%d and it's value is %d\n", i+1, indexOfMin+1, min);
    }
}

void findMaximum(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    int i, j, max, indexOfMax;
    for(i = 0; i < MATRIX_SIZE; i++) {
        max = 0;
        indexOfMax = 0;
        for(j = 0; j < MATRIX_SIZE; j++) {
            if(matrix[i][j] > max) {
                max = matrix[i][j];
                indexOfMax = j;
            }
        }
        printf("Maximum number on row #%d is on column #%d and it's value is %d\n", i+1, indexOfMax+1, max);
    }
}
