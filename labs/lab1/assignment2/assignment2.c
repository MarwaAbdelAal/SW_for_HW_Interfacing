#include <stdio.h>

/* This is my second lab assignment */
/* Inputs three different integers, then prints the sum, the average, the product, the smallest and the largest of these numbers */

int main(void)
{
    int num1, num2, num3;
    int sum, smallest, largest, product = 0;
    float average = 0;

    printf("Please enter three different integers: ");

    // Take three different integers from the user
    scanf("%d%d%d", &num1, &num2, &num3);

    // Calculate the sum, average and product of them
    sum = num1 + num2 + num3;
    average = sum / 3.0;
    product = num1 * num2 * num3;

    // Find the largest number
    largest = (num1 > num2) ? num1 : num2;
    largest = (largest > num3) ? largest : num3;
  
    // Find the smallest number
    smallest = (num1 < num2) ? num1 : num2;
    smallest = (smallest < num3) ? smallest : num3;
  
    printf("Sum is %d\n", sum);
    printf("Average is %0.3f\n", average);
    printf("Product is %d\n", product);
    printf("Smallest is %d\n", smallest);
    printf("Largest is %d\n", largest);

    return 0;
}