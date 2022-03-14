/*Your are given a quadratic equation with integral coefficients and have been asked to calculate the roots of the same. The form if the equation is a*x*x + b*x + c = 0 where a, b and c are constants.


Input Format

The first and only line of the input contains the three integers a, b and c.


Output Format

In the first line, you print REAL, or COMPLEX depending on whether the roots are real or complex. If the roots are real, then you print the roots in the next two lines, the smaller root getting printed first. If the roots are complex you print the two roots in the next two lines, by printing the real and imaginary parts separated by a space. The root with a negative imaginary part comes first.
Note that all numbers have to be rounded off to 3 decimal places before printing.


input
5 0 -3
output
REAL
-0.775
0.775*/

// solution:

#include <stdio.h>
#include <math.h>
int main()
{
    // Insert your code here.
    float a;
    float b;
    float c;
    scanf("%f %f %f", &a, &b, &c);
    if (a == 0)
    {
        printf("REAL\n%.3f\n%.3f", (float)((-1 * c) / b), (float)((-1 * c) / b));
        return 0;
    }
    float discr = (float)((b * b) - (4 * a * c));
    if (discr < 0)
    {
        printf("COMPLEX\n");
        float d = sqrt(-1 * discr);
        float re = (float)(b / (-2 * a));
        if (a < 0)
        {
            printf("%.3f %.3f\n", re, d / (2 * a));
            printf("%.3f %.3f", re, d / (-2 * a));
        }
        else
        {
            printf("%.3f %.3f\n", re, d / (-2 * a));
            printf("%.3f %.3f", re, d / (2 * a));
        }
    }
    else
    {
        printf("REAL\n");
        float d = sqrt(discr);
        float re = (float)(b / (-2 * a));
        float x1 = re + (float)(d / (2 * a));
        float x2 = re - (float)(d / (2 * a));
        if (x1 < x2)
        {
            printf("%.3f\n%.3f", x1, x2);
        }
        else
        {
            printf("%.3f\n%.3f", x2, x1);
        }
    }
    return 0;
}