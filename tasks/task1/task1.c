#include <stdio.h>

/* Calculate the exponential function using Taylor series, 
    the program asks the user to enter the exponent and the number of iterations and then print the exponential result.
*/

int main() 
{
    int iterations;
    float exponent;
    int i = 0;
    float result = 1;  // first term of taylor series

    printf("Please enter the exponent\n");
    scanf("%f", &exponent);

    printf("Please enter the number of iterations\n");
    scanf("%d", &iterations);

    float term = exponent;

    // iterate over the number of iterations to calculate the exponential function
    for(i = 1; i < iterations; i++)
    {
        result = result + term;               // sum up the terms
        term = term * (exponent / (i + 1));  // to calculate the next term
    }

    printf("The exponential result of e^%0.2f is %0.3f \n", exponent, result);

    return 0;
}