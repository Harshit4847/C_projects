#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {9,8,7,6,5,4,3,2,1};
    for(int j = 0; j < 9; j++){
        for(int i = 0; i < 9 - j - 1; i++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }

    for(int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
}
