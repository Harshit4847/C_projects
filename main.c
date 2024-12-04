#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int rno, n, att = 0;


    srand(time(0));
    rno = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have chosen a number between 1 and 100. Can you guess it?\n");

    do {
        printf("Guess the number I have chosen: ");
        scanf("%d", &n);

        att++;

        if (n < rno) {
            printf("No, I have chosen a number larger than this.\n");
        } else if (n > rno) {
            printf("No, I have chosen a number smaller than this.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", att);
        }

    } while (n != rno);

    return 0;
}
