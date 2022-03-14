/*Given the denominations of currencies available in the new system, find the number of ways an ATM machine can generate notes for an entered amount N.


Input:

First line contains an integer n denoting the number of different denominations available in the new currency system.
Second line contains n space-separated integers denoting the denominations in increasing order.
Next line contains t denoting the number of test-cases.
Next line contains t integers, each representing the amount entered in the ATM.


Output:

For each of the t test-cases, in a new line output the number of ways the ATM machine can generate notes for the respective amount entered.


Constraints:


1 <= n <= 10

1 <= denominations <= 100

1 <= t <= 10

1 <= amounts <= 1000


Sample Input:

3
2 3 5
1
10
Sample Output:

4
Explanation:

The four possible note combinations which can be delivered by the ATM are as follows:



10 = 5 + 5

10 = 5 + 3 + 2

10 = 3 + 3 + 2 + 2

10 = 2 + 2 + 2 + 2 + 2*/

// solution:

#include <stdio.h>
void recursion(int arr[], int in, int n, int s, int *count, int istart)
{
    if (in == s)
    {
        *count = *count + 1;
        return;
    }
    if (in > s)
    {
        return;
    }
    for (int i = istart; i < n; i++)
    {
        istart = i;
        recursion(arr, in + arr[i], n, s, count, istart);
    }
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int s;
    int t;
    scanf("%d", &t);
    for (int y = 0; y < t; y++)
    {
        int count = 0;
        scanf("%d", &s);
        recursion(arr, 0, n, s, &count, 0);
        printf("%d\n", count);
    }
}
