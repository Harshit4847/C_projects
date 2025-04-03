#include <stdio.h>
#include <stdlib.h>

struct complex {

    float real;
    float imag;
};

struct complex add(struct complex c1, struct complex c2){
    struct complex result;
    result.real = c1.imag + c2.real;
    result.imag = c1.real + c2.imag;
    return result;
}
int main()
{
    struct complex c1,c2, sum;
    printf("Enter the real no :");
    scanf("%f %f", &c1.real, &c2.imag);
    printf("Enter the imag no :");
    scanf("%f %f", &c2.real, &c1.imag);

    sum = add(c1, c2);
    printf("%d", sum.real, sum.imag);
    return 0;
}
