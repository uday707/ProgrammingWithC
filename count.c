#include <stdio.h>
#include <ctype.h>
#include <string.h>


/* Number of types of characters */
#define NTYPES 4
enum CHAR_TYPE { NONE, VOWEL, CONSONANT, SPACE };

char vowels[] = "aeiouAEIOU";

enum CHAR_TYPE get_type (char c) {
    
    enum CHAR_TYPE retval = NONE;
    
    if (c == ' ') 
        retval = SPACE;
    else if (isalpha(c)) {
         if ( strchr ( vowels, c)) {
              retval = VOWEL;
         } else {
              retval = CONSONANT;
         }
    }

    return retval;
}

void main () {
  
    char input[80];
    int len, i;
    int counts[NTYPES] = { 0, 0, 0, 0 };
   
    puts("Enter the line of text: ");
    gets(input);
    len = strlen (input);
   
    for(i = 0; i < len; i++) {
        int index = get_type ( input[i] );
        counts[index]++;
    }

    printf("Results:\n");
    printf( "  Vowels: %d\n", counts[VOWEL]);
    printf( "  Consonants: %d\n", counts[CONSONANT]);
    printf( "  Spaces: %d\n", counts[SPACE]);
}
    

