/*Given an array of integers, is it possible to divide them into two groups so that the sums of the two groups are the same.


Input:

First Line of input will be an integer n, denoting the number of elements in array. Next line will consist of n space separated integers.


Output:

Print "YES" if it's possible otherwise print "NO".


Constraints:


n <= 20


Sample Input:

4
1 2 3 4
Sample Output:

YES
Explanation:


1 + 4 = 2 + 3 = 5*/

// solution:

/*#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int s = 0;;
    scanf("%d" , &n);
    int *arr = (int *)malloc(n*(sizeof(int)));
    for(int i=0;i<n;i++)
    {
        scanf("%d" , arr+i);
        s += *(arr+i);
    }
    int flag = 0;
    if(s % 2 == 0)
    {
        s = s/2;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum = 0;
            for(int p=i;p<=j;p++)
            {
                sum += *(arr+p);
            }
            if(sum == s)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
    }
    if(flag == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
int recursive(int n, int arr[], int s)
{
    if (n == 0)
    {
        return 0;
    }
    if (s == 0)
    {
        return 1;
    }
    return (recursive(n - 1, arr, s)) || recursive(n - 1, arr, s - arr[n - 1]);
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        printf("NO");
    }
    else
    {
        sum = sum / 2;
        if (recursive(n, arr, sum) == 1)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
    }
}