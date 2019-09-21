#include <stdio.h>
#include <string.h>
#define NUM_OF_BOOKS 2
#define STR_MAX_RANGE 256

struct Book {
    char name[STR_MAX_RANGE];
    char title[STR_MAX_RANGE];
    float price;
};

int main() {
    struct Book library[NUM_OF_BOOKS];
    int i = 0, counter = 0;
    float price = 0.0;
    size_t length;

    while(i < NUM_OF_BOOKS){

        printf("Enter author's name: ");
        fgets(library[i].name, STR_MAX_RANGE, stdin);

        /*
            Και στις δύο περιπτώσεις αφού παίρνω με την fgets το string που θέλω μένει στο τέλος του
            string ένα end of line (το οποίο έχει μπει επειδή πατάω το enter). Με τις παρακάτω 4 γραμμές κώδικα
            αντικαθιστώ αυτό το '\n' με το '\0'. Το κάνω για να μην μου δημιουργεί προβλήματα με τα new lines
            όταν εκτυπώνω πράγματα.
        */

        length = strlen(library[i].name) - 1;
        if (*library[i].name && library[i].name[length] == '\n'){
            library[i].name[length] = '\0';
        }

        printf("Enter book's title: ");
        fgets(library[i].title, STR_MAX_RANGE, stdin);

        length = strlen(library[i].title) - 1;
        if (*library[i].title && library[i].title[length] == '\n'){
            library[i].title[length] = '\0';
        }

        printf("Enter book's price: ");
        scanf("%f", &library[i].price);

        printf("\n\tbook inserted\n");
        printf("name: %s\ntitle: %s\nprice: %f\n\n", library[i].name, library[i].title, library[i].price);
        /*
            Μετά τη χρήση της scanf αποθηκεύεται στην μνήμη η τιμή του βιβλίου αλλά στον buffer
            αφήνει τον new line χαρακτήρα (επειδή πατάω enter). Οπότε κάνω ένα ξερό getchar(),
            για να πάρω από τον buffer το new line character. Αν δεν το κάνω αυτό στην επόμενη επανάληψη,
            που θα προσπαθήσω να ζητήσω από τον χρήστη να εισάγει ένα όνομα συγγραφέα, θα αποθηκευτεί
            κατευθείαν ως όνομα συγγραφέα το new line και θα μου ζητήσει να εισάγω μόνο τον τίτλο του βιβλίου.
        */
        getchar();
        i++;
    }

    printf("Give a price: ");
    scanf("%f", &price);
    printf("\n");

    for(i = 0; i < NUM_OF_BOOKS; i++) {
        if(library[i].price == price) {
            printf("%s by %s has price %f\n", library[i].title, library[i].name, price);
            counter++;
        }
    }

    if (counter == 0) {
        printf("There is no book on price %f\n", price);
    } else {
        printf("There are %d book(s) that has price %f\n", counter, price);
    }

    return 0;
}
