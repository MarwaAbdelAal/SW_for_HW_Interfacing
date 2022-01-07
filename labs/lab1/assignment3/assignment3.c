#include <stdio.h>

/* This is my third lab assignment */
/* Input total time elapsed , in seconds, and converts it to hours, minutes and seconds 
    the time should be displayed as hrs:mins:secs */

int main(void)
{
    int seconds, minutes, hours = 0;
    float time;

    // Take the total time elapsed from the user
    printf("Enter the seconds \n");
    scanf("%f", &time);

    // Convert time into hrs, mins and secs
    hours = time / 3600;
    minutes = ((time - hours * 3600) / 60);
    seconds = (time - (hours * 3600) - (minutes * 60));

    printf("Time is %d : %d : %d\n", hours, minutes, seconds);

    return 0;
}