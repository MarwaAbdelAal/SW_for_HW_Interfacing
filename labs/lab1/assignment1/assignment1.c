#include <stdio.h>

/* This is my first lab assignment */
/* Enter the initial velocity, acceleration of an object and the time that has elapsed, 
    places them in the variables u, a, and t and prints the final velocity and distance traversed
    using these equations (v = u + at), (s = ut + 0.5at^2) */

int main(void)
{
    float initialVelocity, acceleration, time, finalVelocity, distance;

    printf("Please enter the initial velocity\nu = ");
    scanf("%f", &initialVelocity);

    printf("Please enter the acceleration\na = ");
    scanf("%f", &acceleration);

    printf("Please enter the time\nt = ");
    scanf("%f", &time);

    // Compute final velocity v = u + at
    finalVelocity = initialVelocity + acceleration * time;  

    // Compute distance traversed s = ut + 0.5 at^2
    distance = initialVelocity * time + 0.5 * acceleration * time * time; 

    printf("\nFinal velocity = %0.2f\n", finalVelocity);
    printf("Distance = %0.2f\n", distance);

    return 0;
}