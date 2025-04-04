#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int num){

    if ( num <= 1){
        return 0;
    }

    for(int i = 2; i * i <= num; i++){
        if( num % i == 0){
            return 0;
        }
    }

    return 1;
}

int fap(int num){
    int count = 0;
    int org = num;
    int sum = 0;
    while (org != 0){
        org /= 10;
        count++;
    }

    org = num;

    while ( org != 0){
        int rev = org % 10;
        sum += pow(rev,count);
        org /= 10;
    }

    return sum == num;
}
int main()
{
    int num = 0;
    scanf("%d", &num);
    if(prime(num)){
        printf("prime ha\n");
    }else{
        printf("prime nhi ha\n");
    }

    if(fap(num)){
        printf(" ha");
    }else{
        printf(" nhi ha");
    }
}
