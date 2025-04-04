#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[6] = "Hello";
    char str1[7] = " world";
    char result [20];

    int i = 0, j = 0;
    while ( i < 5){
        result[i] = str[i];
        i++;
    }

    while (j < 7){
        result[i + j] = str1[j];
        j++;
    }

    result[i + j] = '\0';
    printf("%s", result);
}
