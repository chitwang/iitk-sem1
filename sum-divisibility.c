/*You are given an array of size of n. All the elements of the array are non-negative integers. Check if the sum of all the elements present at even indices of the array is even.


Input: You will be given a positive integer n, followed by n non-negative integers.


Output: Print YES if the required sum is even and NO otherwise.


Examples:


Input 1

4 1 2 3 4


Output 1

YES


Explanation 1

1 + 3 = 4 which is even.


Input 2

9 1 2 3 4 5 6 7 8 9


Output 2

NO


Explanation 2

1 + 3 + 5 + 7 + 9 = 25 which is odd. */

// solution:

#include <stdio.h>

int main()
{
    int n;
    int sum = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (i % 2 == 0)
        {
            sum = sum + arr[i];
        }
    }
    if (sum % 2 == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}