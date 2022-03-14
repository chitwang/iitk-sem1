/*Alice and Bob are invited to their friend Charlie’s birthday party. Charlie is a mathematics enthusiast and really likes numbers, but in an orderly fashion. Alice has an array of N numbers in an increasing order. Bob has an array of M numbers in an increasing order. Alice and Bob wish to combine their presents and give Charlie an array of N+Mnumbers in an increasing order. You need to output the final present given to Charlie.


Input Format:

The first line contains an integer N.

The second line contains Alice’s present (N space separated integers).

The third line contains an integer M.

The fourth line contains Bob’s present (M space separated integers).


Output Format:

Output will contain N+M spaced separated numbers i.e. Charlie's birthday present. All the starting N+M-1 integers will be followed by a space (' ') and the last integer will be followed by next line ('\n').


Public Test Cases

Test Case	Output
5
44 67 78 89 100
4
41 55 63 89	41 44 55 63 67 78 89 89 100

Grading Scheme:
Visible Testcase : 2 marks
Hidden Testcases : 3 marks each*/

// solution:

#include <stdio.h>
#include <stdlib.h>
void scan(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
}
void sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(arr + i) > *(arr + j))
            {
                int a = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = a;
            }
        }
    }
}
int main()
{
    int n;
    int m;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * (sizeof(int)));
    scan(arr, n);
    scanf("%d", &m);
    int *brr = (int *)malloc(m * (sizeof(int)));
    scan(brr, n);
    int *gift = (int *)malloc((n + m) * (sizeof(int)));
    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
        {
            *(gift + i) = *(arr + i);
        }
        else
        {
            *(gift + i) = *(brr + i - n);
        }
    }
    sort(gift, n + m);
    for (int i = 0; i < n + m; i++)
    {
        printf("%d", *(gift + i));
        if (i < n + m - 1)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}