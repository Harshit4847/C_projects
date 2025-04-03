#include <stdio.h>
#include <stdlib.h>

struct distance {
    int feet;
    int inch;
}d1,d2,sum;
int main()
{
    printf("enter the feet of place 1:\n");
    scanf("%d", &d1.feet);
    printf("Enter the inch of place 1:\n");
    scanf("%d", &d1.inch);

    printf("enter the feet of place 2:\n");
    scanf("%d", &d2.feet);
    printf("Enter the inch of place 2:\n");
    scanf("%d", &d2.inch);

    sum.feet = d1.feet + d2.feet;
    sum.inch = d2.inch + d2.inch;

    if(sum.inch >= 12){
        sum.feet += sum.inch / 12;
        sum.inch = sum.inch % 12;

    }

    printf("\n--- Total Distance ---\n");
    printf("%d feet and %d inches\n", sum.feet, sum.inch);

    return 0;
}
