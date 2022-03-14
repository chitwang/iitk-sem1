/*Coordinates (x, y) of the center of a circle and its radius (say r) are given as input. Another point, say (x1, y1),  is provided as input. Write a program to find out whether the point is inside the circle, on the circle, or outside the circle. Assume x, y, r, x1, y1 are of float data type. Print Yes if the point is inside or on the circle and print No otherwise.


There should be no newline or spaces after the Yes or No words.

Input Format: x y r x1 y1 are separated by a single space.

Sample Input 1:

3.2 4.3 2.3 4.3 5.6

Output:

Yes

Sample Input 2:

1.2 2.3 2.0 5.3 7.6

Output:

No*/

// solution:

#include <stdio.h>

int main()
{
    float x, y, r, x1, y1, d;
    scanf("%f%f%f%f%f", &x, &y, &r, &x1, &y1);
    if (r * r >= ((x1 - x) * (x1 - x)) + ((y1 - y) * (y1 - y)))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}