#include <stdio.h>

/* This is my second lab assignment */
/* Write a program that prints diamond shape */ /*
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/

int main(void)
{
    int i, j;
    int n = 5; // number of rows of upper traingle

    // draw upper traingle
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
            printf(" ");

        for (j = 1; j <= 2 * i - 1; j++)
            printf("*");

        printf("\n");
    }

    // draw lower traingle
    for (i = 1; i <= n - 1; i++)
    {
        for (j = 1; j <= i; j++)
            printf(" ");

        for (j = 1; j <= 2 * (n - i) - 1; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}