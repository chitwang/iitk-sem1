/*Given an array of N integers, is it possible to choose a group of some of the integers, such that the group sums to the given target T.
Input will consist of two lines : space separated integers N and T in first line followed by N space separated integer elements (a1 ... aN ) of array in second line.
Output should be single line - either "YES" or "NO".


Constraints:

0 <= N <= 15


Sample Input:

4 2

3 5 7 1


Sample Output:

NO


Public test cases:

Input

4 2
3 5 7 1

output:
NO*/

// solution:

#include <stdio.h>
void recursion(int arr[], int in, int n, int s, int istart, int sub[], int j, int *flag)
{
    if (in == s)
    {
        *flag = *flag + 1;
        return;
    }
    if (in > s)
    {
        return;
    }
    for (int i = istart; i < n; i++)
    {
        istart = i;
        sub[j] = arr[istart];
        recursion(arr, in + arr[i], n, s, istart + 1, sub, j + 1, flag);
    }
    return;
}
int main()
{
    int n;
    int s;
    scanf("%d", &n);
    scanf("%d", &s);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sub[n];
    int flag = 0;
    recursion(arr, 0, n, s, 0, sub, 0, &flag);
    if (!flag)
        printf("NO");
    else
        printf("YES");
}
