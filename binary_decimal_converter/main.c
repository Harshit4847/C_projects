#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int desimaltobinary(int num){

    int org = num, i = 0;
    int rev[100];
    while(org != 0){
        rev[i] = org % 2;
        org /= 2;
        i++;
    }
    printf("the binary of this is: ");
    for(int j =  i - 1; j >= 0; j--){
        printf("%d", rev[j]);
    }
    printf("\n");
}

int binarytodesimal(int num){
    int org = num;
    int rev[100];
    int sum = 0;
    for(int i = 0; org != 0; i++){
        int pop = org % 10;
        sum += pop * pow(2,i);
        org /= 10;
    }
    printf("the desimal of this is %d\n", sum);
}
int main()
{
    int num, dem;
    scanf("%d", &num);
    desimaltobinary(num);

    scanf("%d", &dem);
    binarytodesimal(dem);
}
