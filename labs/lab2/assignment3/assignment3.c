#include <stdio.h>

/* This is my third lab assignment */
/* print the number of the Fibonacci series terms after reading it from a user input */

int main() 
{
    int i, num;

    // initialize first and second terms
    int term_1 = 0, term_2 = 1;
  
    // initialize the next term (3rd term)
    int nextTerm = term_1 + term_2;
  
    // get number of terms from input user
    printf("Enter the number of Fibonacci series terms: ");
    scanf("%d", &num);

    switch(num) {

        // if the user entered number 0
        case(0): {
            break;
        }

        // if the user entered number 1
        case(1): {
            printf("Fibonacci Series: %d", term_1);
        }
        break;

        // if the user entered number 2
        case(2): {
            printf("Fibonacci Series: %d, %d", term_1, term_2);
        }
        break;

        // if the user entered any other number greater than 2
        default: {
            // print the first two terms term_1 and term_2
            printf("Fibonacci Series: %d, %d, ", term_1, term_2);
    
            // print 3rd to nth terms
            for (i = 3; i <= num; ++i) {
                printf("%d, ", nextTerm);
                term_1 = term_2;
                term_2 = nextTerm;
                nextTerm = term_1 + term_2;
            }
        }
    }

    printf("\n");
  
    return 0;
}