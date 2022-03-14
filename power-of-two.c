/*You are a new intern at a famous multinational company. Your first task given by your manager is as follows.


You are provided with a number N where N is an integer strictly smaller than 128. First, you have to check if N is positive. If N is a positive integer, then find the count of number of positive powers of 2 which are smaller than N. Print all the positive powers of 2 which are less than N.


Input Format: N


The number N is an integer and is strictly smaller than 128.


Output Format:


If N is not a positive integer, then print "Invalid Input" (without quotes, the quotes are for emphasis). If N is a positive integer, the output may span upto 2 lines. In the first line, print the count of positive powers of 2 which are less than N. In the following line, print all the powers of 2 which are less than N.


Example Input
10

Example Output:
3
2 4 8

Note: You are only allowed to use "stdio.h" header file and only "int" data structure for the above problem*/

#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    if (N <= 0)
    {
        printf("Invalid Input");
    }
    else
    {
        if (N > 64)
        {
            printf("6\n");
            printf("2 4 8 16 32 64");
        }
        else if ((N > 32) && (N <= 64))
        {
            printf("5\n");
            printf("2 4 8 16 32");
        }
        else if ((N > 16) && (N <= 32))
        {
            printf("4\n");
            printf("2 4 8 16");
        }
        else if ((N > 8) && (N <= 16))
        {
            printf("3\n");
            printf("2 4 8");
        }
        else if ((N > 4) && (N <= 8))
        {
            printf("2\n");
            printf("2 4");
        }
        else if ((N > 2) && (N <= 4))
        {
            printf("1\n");
            printf("2");
        }
        else if ((N == 1) || (N == 2))
        {
            printf("0");
        }
    }
    return 0;
}