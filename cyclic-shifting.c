/*[40 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Public Test Cases (2.5 point each. 2.5*2 = 5 points)
Hidden Test Cases (5 point each. 5*7 = 35 points)

Manual Grading Scheme
Note: Any form of hard-coding will lead to zero marks. Eg: printf("0");
----------------------------------------------------------------------

Dragnoid is the emperor of Dragon City. One day, Tourist visited Dragon city. Dragnoid offered him gold coins that would make Tourist rich if he could solve a problem. Unfortunately, Tourist cannot solve the problem, so he asks you to help him solve the problem.

The problem goes as follows. You are given an array consisting of n integers. You have to process some queries which will modify the array and print the resulting array after each query. In each query, two numbers l and r are provided such that l>=0, r>=l, and r. In each query, two types of cyclic shifts are involved.

    The elements that are at a position between l and r (inclusive) and at an even distance from l, i.e. positions {x | x>=l and x<=r and (x-l)%2 = 0}, are shifted cyclically left by an offset of 1
    The elements that are at a position between l and r (inclusive) and at an odd distance from l, i.e. positions {x | x>=l and x<=r and (x-l)%2 = 1}, are shifted cyclically right by an offset of 1

A left cyclic shift by an offset 1 of an array A = {a[l], a[l+1], a[l+2], a[l+3], … a[r-1], a[r]} results in the array {a[l+1], a[l+2], a[l+3], … a[r], a[l]}. A right cyclic shift by an offset 1 of the array A results in the array {a[r], a[l+1], a[l+2], … a[r-2], a[r-1]}.

After each query, you will have to print the resulting array in a new line and use the new array as the initial array for the next input. Note the original array gets modified after a query, and the next query will be executed on the transformed array.

Input Format

The first line contains two integers, the number of elements in the array n and the number of queries q. The second line contains the array arr. The following q lines contain two integers, l and r each, representing one query.

Output Format

The output will contain a total of q lines, ith linw will contain the resulting array after ith query.

Example Input

6 3
1 2 3 4 5 6
0 5
2 2
3 5

Example Output

3 6 5 2 1 4
3 6 5 2 1 4
3 6 5 4 1 2

Explanation

In the first query, we have cyclically left-shifted the numbers at positions {0,2,4} by an offset 1, and cyclically right-shifted the numbers at positions {1,3,5} by an offset 1. So, the resulting array will be {3,6,5,2,1,4}.*/

// solution:

#include <stdio.h>
void right(int arr[], int n)
{
    int x = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
}
void left(int arr[], int n)
{
    int x = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = x;
}
int main()
{
    int n;
    int q;
    scanf("%d %d", &n, &q);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int brr[n];
    int crr[n];
    int l;
    int r;
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &l, &r);
        int a = 0;
        int b = 0;
        for (int j = l; j <= r; j++)
        {
            if ((j - l) % 2 == 0)
            {
                brr[a] = arr[j];
                a++;
            }
            else
            {
                crr[b] = arr[j];
                b++;
            }
        }
        left(brr, a);
        right(crr, b);
        for (int j = l; j <= r; j++)
        {
            if ((j - l) % 2 == 0)
            {
                arr[j] = brr[(j - l) / 2];
            }
            else
            {
                arr[j] = crr[(j - l) / 2];
            }
        }
        for (int y = 0; y < n; y++)
        {
            printf("%d", arr[y]);
            if (y < n - 1)
            {
                printf(" ");
            }
        }
        if (i < q - 1)
        {
            printf("\n");
        }
    }
}