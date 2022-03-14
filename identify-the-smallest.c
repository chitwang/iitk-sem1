/*Given a sequence of N number, identify the smallest number among them. Each positive integer will be smaller than 1000.


Input:

Each test case will span across 2 lines.
First line with specify N the length of sequence.
Second line will contain N positive numbers.


Output:

The output of the program will be the smallest number in the sequence.



Sample Testcase


Testcase1:

Input
10
8 34 52 98 123 10 2 19 11 23
Output

2*/

// solution:

#include <stdio.h>

int main()
{
    int N;
    int min = 10000000;
    int a;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        if (a < min)
        {
            min = a;
        }
    }
    printf("%d", min);
    return 0;
}
