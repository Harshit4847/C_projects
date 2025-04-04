#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[50], size = 0;
    printf("Enter the size: ");
    scanf("%d", &size);

    printf("enter the elements");
    for( int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("the element you enterd are\n");
    for(int i = 0; i < size; i++){
        printf("%d ,",arr[i]);
    }
}
