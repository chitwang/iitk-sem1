/*Write a program that reads 5 integers as input, and outputs their mean (denoted by me) and mode (denoted by mo). The output will be in float, rounded up to three decimal places. You can assume that the mode will be unique.

[Hint : To compute mode make use of 5 extra variables to store the count of respective variables. For example countA to store the number of occurrences of variable a. To do so compare a with each of b,c,d,e and update countA accordingly]

Input:
a b c d e

Output:
mean = me
mode = mo

Sample Input 1:
0 4 3 4 4

Sample Output 1:
mean = 3.000
mode = 4.000

Sample Input 2:
-25 -2 -10 -25 -1

Sample Output 2:
mean = -12.600
mode = -25.000

NOTE: Do not hard code the output for the test cases, that is wrong, is bad practice, and you will get a 0.*/

//SOLUTION 

#include <stdio.h>
int main()
{
    int a, b, c, d, e;
    int oa = 0;
    int ob = 0;
    int oc = 0;
    int od = 0;
    int oe = 0;

    float mode, mean;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &e);
    mean = (float)(a + b + c + d + e) / 5;

    if (a == b)
    {
        oa++;
        ob++;
    }
    if (b == c)
    {
        ob++;
        oc++;
    }
    if (b == d)
    {
        ob++;
        od++;
    }
    if (d == c)
    {
        od++;
        oc++;
    }
    if (e == c)
    {
        oe++;
        oc++;
    }
    if (b == e)
    {
        ob++;
        oe++;
    }
    if (d == e)
    {
        od++;
        oe++;
    }
    if (a == e)
    {
        oa++;
        oe++;
    }
    if (a == c)
    {
        oa++;
        oc++;
    }
    if (a == d)
    {
        oa++;
        od++;
    }
    if ((oa > ob) && (oa > oc) && (oa > od) && (oa > oe))
    {
        mode = (float)a;
    }
    else if ((ob > oc) && (ob > od) && (ob > oe))
    {
        mode = (float)b;
    }
    else if ((oc > od) && (oc > oe))
    {
        mode = (float)c;
    }
    else if ((od > oe))
    {
        mode = (float)d;
    }
    else
    {
        mode = (float)e;
    }
    printf("mean = %0.3f\n", mean);
    printf("mode = %0.3f", mode);
}


