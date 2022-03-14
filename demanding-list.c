/*[100 Points]

----------------------------------------------------------------------
Grading Scheme:
Visible Testcase : 5 marks each
Hidden Testcases : 45 marks each
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Using future concept will deduct 20% marks
Using other header files except stdio.h will lead to penalize 20% marks


Write code recursively, otherwise, 0 marks will be given.


Subsequence of an array

A subsequence of an array is an ordered subset of the array's elements having the same sequential ordering as the original array. It can be obtained by deleting one or more elements form the array, while preserving the order of the remaining elements.


Example : For the array {1,2,3,4,5,6,7} we have valid subsequences as {1}, {2}, {1,2}, {1,4}, {2,3,6}, {1,2,5,7}. Some invalid subsequences would be {2,1}, {4,1,6}, {2,1,3,6,7}.


Problem Statement

We define a special sum of a sequence [a[0], a[1], .... a[n-1]] as 1*a[0] + 2*a[1] + .... + n*a[n-1].
 Given an integer n, an array a of n elements, and an integer sum, print "YES" (without quotes) if the array has a subsequence with special sum equal to sum. Else print "NO" (without quotes).


You will be given t testcases per input. Print the answer for each testcase in a separate line. Make sure there are no unnecessary whitespaces.


Input Format

The first line contains an integer t, denoting the number of testcases. 3t lines follow, 3 lines for each input.
 The first line of each input contains an integer n, denoting the number of elements in the array.
 The second line contains n space-separated integers, denoting the elements of array a.
 The third line contains a single integer sum, denoting the target sum.


Output Format

For each testcase, print either "YES" or "NO" (without quotes).


Example Input

2
5
2 3 5 8 11
19
6
1 4 5 12 4 6
7
Example Output

YES
NO
Explanation

For the first testcase, we see that {3,8} is a valid subsequence since 1*3 + 2*8 = 19
For the second testcase, there does not exist any subsequence whose special sum is 7
*/

// solution:

#include <stdio.h>
void recursion(int arr[], int in, int n, int s, int istart, int sub[], int j, int *flag)
{
    if (in == s)
    {
        *flag = *flag + 1;
        return;
    }
    if (in != s && istart >= n)
    {
        return;
    }
    for (int i = istart; i < n; i++)
    {
        istart = i;
        sub[j] = arr[istart];
        recursion(arr, in + (j + 1) * arr[i], n, s, istart + 1, sub, j + 1, flag);
    }
}
int main()
{
    //  Insert your code here.
    int t;
    int sum;
    int n;
    scanf("%d", &t);
    int arr[1000];
    int sub[1000];
    for (int g = 0; g < t; g++)
    {
        int flag = 0;
        scanf("%d", &n);
        // printf("%d\n" , n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            // printf("%d " , arr[i]);
        }
        scanf("%d", &sum);
        // printf("\n%d\n" , sum);
        recursion(arr, 0, n, sum, 0, sub, 0, &flag);
        if (flag == 0)
        {
            printf("NO");
        }
        else
        {
            printf("YES");
        }
        if (g < t - 1)
        {
            printf("\n");
        }
    }
    return 0;
}