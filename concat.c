#include<stdio.h>
#include<string.h>

void main() {
   
    char str1[80], str2[40];
    int i1, i2;

    printf("Input the first string: ");
    gets(str1);

    printf("Input the second string: ");
    gets(str2);

    /* i1 is the index to str1 and i2 is the index to str2  */
    i1 = strlen(str1);
    i2 = 0;
   
    for(i1 = strlen(str1), i2 =0; str2[i2]; i1++, i2++)
        str1[i1] = str2[i2];

    str1[i1] = 0;

    puts("The Concatenated string is....");
    puts(str1);
}
