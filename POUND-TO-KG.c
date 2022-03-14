/*Write a C Program to convert Pounds to Kilograms (1 pound = 0.454 kg).Your C program should input a single float value, this would be the value in Pounds.
And the output should be a single float value rounded upto three decimal place, this would be the value in Kilograms.
For Example:

Sample Input 1:

10.0

Sample Output 1:

4.540

Sample Input 2:

2.202

Sample Output 2:

1.000*/

// SOLUTION

#include <stdio.h>

int main()
{
    float kgs, pounds;
    scanf("%f", &kgs);
    pounds = kgs * 0.454;
    printf("%0.3f", pounds);
    return 0;
}