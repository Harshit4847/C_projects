#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a,b,r;
  char op;

      printf("Enter the first no:");
      scanf("%d", &a);

      printf("Enter the srcond no:");
      scanf("%d", &b);

      printf("Ok what task do you wanaa  perform\n 1.+\n 2.-\n 3./\n 4.*\n");
      scanf(" %c", &op);

      switch(op){

      case '+':
        r = a + b;
        printf("%d", r);
        break;

      case '-':
        r = a - b;
        printf("%d", r);
        break;

      case '/':
        r = a / b;
        printf("%d", r);
        break;

        case '*':
        r = a * b;
        printf("%d", r);
        break;
      }

}
