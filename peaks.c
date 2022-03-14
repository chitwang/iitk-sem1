/*Given an array A1, A2,... An of n integers ( 2 < n < 100 ).

Find total number of peaks in the array. An element Ai (i > 1 and i < n) is a peak iff Ai > Ai-1 and Ai > Ai+1.


Input Format:

The first line of input contains the size n of the array.

The second line contains n space-separated integers denoting elements of the array.


Output Format:

You must output an integer which is the answer to the question.


Sample Input 1:

3

1 3 2


Sample Output 1:

1


Explanation:

A2 = 3 is the only peak here.


Sample Input 2:

4

1 2 3 4


Sample Output 2:

0


Explanation:

There is no peak element in the given array.*/

// solution:

#include <stdio.h>

int main()
{
    int n;
    int peak = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int j = 1; j < n - 1; j++)
    {
        if ((arr[j] > arr[j - 1]) && (arr[j] > arr[j + 1]))
        {
            peak++;
        }
    }
    printf("%d", peak);
    return 0;
}