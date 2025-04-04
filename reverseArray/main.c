#include <stdio.h>
#include <stdlib.h>

int arrayreverse(int *arr, int size){
    int temp = 0;
    int *start = arr;
    int *end = arr + size - 1;
    while (start < end){

        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int size = 0;
    size = sizeof(arr) / sizeof(arr[0]);

    arrayreverse(&arr, size);
    for(int i = 0; i < size; i++){
        printf("%d", arr[i]);
    }

    return 0;
}
