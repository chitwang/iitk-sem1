/*Given two positive integers  num1  and  num2  you have to multiply the numbers and print the result. The numbers num1  and  num2 and their product may be too large to fit in an 'int' or 'long int', so you cannot use the standard C multiplication function.


Input Format

The first and only line of the input contains the two integers num1 and num2.


Output Format

Print the product of the two numbers obtained, i.e., print num1*nm2.


Constraints

0 < num1, num2 < 10^14*/

// solution:

#include <stdio.h>
#include <stdlib.h>
void multiply(int *arr, int *brr, int n1, int n2)
{
    int i, j, carry;
    int *res = (int *)malloc((n1 + n2) * sizeof(int));
    for (i = 0; i < n1 + n2; i++)
    {
        *(res + i) = 0;
    }
    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < n1; j++)
        {
            *(res + i + j) += (*(brr + i)) * (*(arr + j));
        }
    }
    for (i = 0; i < n1 + n2; i++)
    {
        carry = *(res + i) / 10;
        *(res + i) = *(res + i) % 10;
        *(res + 1 + i) = *(res + i + 1) + carry;
    }
    int flag = 0;
    for (int i = n1 + n2 - 1; i >= 0; i--)
    {
        if (*(res + i) > 0)
        {
            flag = 1;
        }
        if (flag == 1)
        {
            printf("%d", *(res + i));
        }
    }
}
int main()
{
    long long int num1;
    long long int num2;
    scanf("%lld", &num1);
    scanf("%lld", &num2);
    int *arr = (int *)malloc(15 * sizeof(int));
    int *brr = (int *)malloc(15 * sizeof(int));
    int n1 = 0;
    int n2 = 0;
    while (num1 != 0)
    {
        *(arr + n1) = num1 % 10;
        num1 = num1 / 10;
        n1++;
    }
    while (num2 != 0)
    {
        *(brr + n2) = num2 % 10;
        num2 = num2 / 10;
        n2++;
    }
    multiply(arr, brr, n1, n2);
}