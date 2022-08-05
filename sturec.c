#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    
    struct record {
      char name[20];
      char regno[10];
      float avg;
      int rank;
    } student[50], temp;

    int i, j, n;
    i = 0;

    printf ("Preprocessing student %d record...\n", i+1);
    printf ("Student name ? (type END to terminate) ");
    scanf ("%s", student[i].name);

    while ( strcmp (student[i].name, "END") > 0) {
           
        printf ("Register number ? ");
        scanf ("%s", student[i].regno);

        printf ("Average marks ? ");
        scanf ("%f", &student[i].avg);
        i++;

        printf ("Processing student %d record...\n", i+1);
        printf ("Student name ? (type END to terminate) ");
        scanf ("%s", student[i].name);
    }

    n = i;
    /* Arranging the student record as per merit */
    for (i = 0; i < n -1; i++)
       for (j = i + 1; j < n; j++) {
           if ( student[i].avg  < student[j].avg) {
                temp = student[i];
                student[i] = student[j];
                student[j] = temp;
           }
       }

    /* Storing the rank in student attribute Rank */
    for(i = 0; i < n; i++) 
        student[i].rank = i+1;

    /* Displaying the students records   */
    printf ("\n\nStudent records after assigning the ranks : \n");
    printf ("\n");
    printf ("NAME          REGISTER_NUMBER           AVERAGE    RANK\n");
    printf ("-------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf ("%-20s %-10s ", student[i].name, student[i].regno);
        printf ("%10.2f     %d \n", student[i].avg, student[i].rank);
    }

    return 0;
}
